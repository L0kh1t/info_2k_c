#include <random>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include "button.hpp"


float getRandomFloat(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> d(min, max);
    return d(gen);
}

float getRandomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> d(min, max);
    return d(gen);
}

sf::Color getRandomColor() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<sf::Uint8> d;
    return sf::Color(d(gen), d(gen), d(gen));
}

class ShapePool {
protected:
    sf::RectangleShape mField;
    std::vector<sf::Shape*> mShapes;
    sf::RenderWindow& mRenderWindow;

public:
    ShapePool(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size)
        : mRenderWindow(window) {
        mField.setPosition(position);
        mField.setSize(size);
        mField.setFillColor(sf::Color(0, 100, 200, 40));
    }

    void addShape(sf::Shape* p) {
        p->setOrigin(p->getGlobalBounds().getSize() / 2.0f);
        sf::Vector2f min = p->getGlobalBounds().getSize() / 2.0f;
        sf::Vector2f max = mField.getSize() - p->getGlobalBounds().getSize() / 2.0f;
        p->setPosition(mField.getPosition() + sf::Vector2f(getRandomFloat(min.x, max.x), getRandomFloat(min.x, max.y)));
        p->setFillColor(getRandomColor());
        mShapes.push_back(p);
    }

    void clearAllShapes() {
        for (auto* p : mShapes)
            delete p;
        mShapes.clear();
    }

    size_t getNumbeorOfShapes() const { return mShapes.size(); }
    sf::Vector2f getPosition() const { return mField.getPosition(); }
    sf::Vector2f getSize() const { return mField.getSize(); }

    sf::Shape& getShape(int index) {
        return *mShapes.at(index);
    }

    std::vector<sf::Shape*>& getShapes() { return mShapes; }
    const std::vector<sf::Shape*>& getShapes() const { return mShapes; }

    void removeShape(sf::Shape* shape) {
        auto it = std::find(mShapes.begin(), mShapes.end(), shape);
        if (it != mShapes.end()) {
            mShapes.erase(it);
        }
    }

    void draw() const {
        for (auto p : mShapes)
            mRenderWindow.draw(*p);
        mRenderWindow.draw(mField);        
    }

    ~ShapePool() {
        for (auto* p : mShapes)
            delete p;
    }
};

class Command {
public:
    virtual void execute() = 0;
    virtual void unexecute() = 0;
    virtual ~Command() = default;
};

class CommandHistory {
private:
    std::stack<Command*> history;
    
public:
    void push(Command* cmd) {
        history.push(cmd);
    }
    
    void undo() {
        if (!history.empty()) {
            history.top()->unexecute();
            delete history.top();
            history.pop();
        }
    }
    
    ~CommandHistory() {
        while (!history.empty()) {
            delete history.top();
            history.pop();
        }
    }
};

class NoCommand : public Command {
public:
    void execute() override {}
    void unexecute() override {}
};

class RotateCommand : public Command {
protected:
    ShapePool& mPool;
    size_t mIndex;
    float mAngle;
    float mLastAngle;

public:
    RotateCommand(ShapePool& pool, size_t index, float angle) 
        : mPool(pool), mIndex(index), mAngle(angle) {}

    void execute() override {
        mLastAngle = mPool.getShape(mIndex).getRotation();
        mPool.getShape(mIndex).rotate(mAngle);
    }

    void unexecute() override {
        mPool.getShape(mIndex).setRotation(mLastAngle);
    }
};

class RandomColorCommand : public Command {
protected:
    ShapePool& mPool;
    size_t mIndex;
    sf::Color mLastColor;

public:
    RandomColorCommand(ShapePool& pool, size_t index) 
        : mPool(pool), mIndex(index) {}

    void execute() override {
        mLastColor = mPool.getShape(mIndex).getFillColor();
        mPool.getShape(mIndex).setFillColor(getRandomColor());
    }

    void unexecute() override {
        mPool.getShape(mIndex).setFillColor(mLastColor);
    }
};

class RandomAllPositionsCommand : public Command {
protected:
    ShapePool& mPool;
    std::vector<sf::Vector2f> mLastPositions;

public:
    RandomAllPositionsCommand(ShapePool& pool) 
        : mPool(pool) {}

    void execute() override {
        mLastPositions.clear();
        for (size_t i = 0; i < mPool.getNumbeorOfShapes(); ++i) {
            mLastPositions.push_back(mPool.getShape(i).getPosition());
            sf::Vector2f min = mPool.getShape(i).getGlobalBounds().getSize() / 2.0f;
            sf::Vector2f max = mPool.getSize() - mPool.getShape(i).getGlobalBounds().getSize() / 2.0f;
            mPool.getShape(i).setPosition(mPool.getPosition() + 
                sf::Vector2f(getRandomFloat(min.x, max.x), getRandomFloat(min.x, max.y)));
        }
    }

    void unexecute() override {
        for (size_t i = 0; i < mPool.getNumbeorOfShapes() && i < mLastPositions.size(); ++i) {
            mPool.getShape(i).setPosition(mLastPositions[i]);
        }
    }
};

class AddNewRandomShape : public Command {
protected:
    ShapePool& mPool;
    float mMinSize;
    float mMaxSize;
    sf::Shape* mAddedShape;

public:
    AddNewRandomShape(ShapePool& pool, float minSize, float maxSize) 
        : mPool(pool), mMinSize(minSize), mMaxSize(maxSize), mAddedShape(nullptr) {}

    void execute() override {
        int r = getRandomInt(0, 2);
        if (r == 0) {
            mAddedShape = new sf::RectangleShape(sf::Vector2f(getRandomFloat(mMinSize, mMaxSize), 
                                              getRandomFloat(mMinSize, mMaxSize)));
        } else if (r == 1) {
            mAddedShape = new sf::CircleShape(getRandomFloat(mMinSize/2, mMaxSize/2));
        } else {
            mAddedShape = new sf::CircleShape(getRandomFloat(mMinSize/2, mMaxSize/2), 3);
        }

        mAddedShape->setFillColor(getRandomColor());
        mAddedShape->rotate(getRandomFloat(0, 360));
        sf::FloatRect bounds = mAddedShape->getGlobalBounds();
        mAddedShape->setPosition({
            mPool.getPosition().x + getRandomFloat(0, mPool.getSize().x - bounds.width),
            mPool.getPosition().y + getRandomFloat(0, mPool.getSize().y - bounds.height)
        });
        mPool.addShape(mAddedShape);
    }

    void unexecute() override {
        if (mAddedShape) {
            mPool.removeShape(mAddedShape);
            delete mAddedShape;
            mAddedShape = nullptr;
        }
    }
};

class RandomAllColorsCommand : public Command {
protected:
    ShapePool& mPool;
    std::vector<sf::Color> mLastColors;

public:
    RandomAllColorsCommand(ShapePool& pool) 
        : mPool(pool) {}

    void execute() override {
        mLastColors.clear();
        for (size_t i = 0; i < mPool.getNumbeorOfShapes(); ++i) {
            mLastColors.push_back(mPool.getShape(i).getFillColor());
            mPool.getShape(i).setFillColor(getRandomColor());
        }
    }

    void unexecute() override {
        for (size_t i = 0; i < mPool.getNumbeorOfShapes() && i < mLastColors.size(); ++i) {
            mPool.getShape(i).setFillColor(mLastColors[i]);
        }
    }
};

class ClearAllShapesCommand : public Command {
protected:
    ShapePool& mPool;
    std::vector<sf::Shape*> mDeletedShapes;

public:
    ClearAllShapesCommand(ShapePool& pool) 
        : mPool(pool) {}

    void execute() override {
        mDeletedShapes = mPool.getShapes();
        mPool.clearAllShapes();
    }

    void unexecute() override {
        for (auto* shape : mDeletedShapes) {
            mPool.getShapes().push_back(shape);
        }
        mDeletedShapes.clear();
    }
};

class MultiCommand : public Command {
protected:
    std::vector<Command*> mCommands;

public:
    MultiCommand(const std::vector<Command*>& commands)
        : mCommands(commands) {}

    void execute() override {
        for (auto* cmd : mCommands) {
            cmd->execute();
        }
    }

    void unexecute() override {
        for (auto it = mCommands.rbegin(); it != mCommands.rend(); ++it) {
            (*it)->unexecute();
        }
    }

    ~MultiCommand() {
        for (auto* cmd : mCommands) {
            delete cmd;
        }
    }
};

class UndoCommand : public Command {
protected:
    CommandHistory& mHistory;

public:
    UndoCommand(CommandHistory& history) : mHistory(history) {}

    void execute() override {
        mHistory.undo();
    }

    void unexecute() override {}
};

class ControlPanel {
protected:
    std::vector<Button*> mButtons;
    std::vector<Command*> mCommands;
    CommandHistory& mHistory;
    sf::RenderWindow& mRenderWindow;

public:
    ControlPanel(sf::RenderWindow& window, CommandHistory& history) 
        : mRenderWindow(window), mHistory(history) {}

    void addButton(Button* p) {
        mButtons.push_back(p);
        mCommands.push_back(new NoCommand);
    }

    void addButton(Button* pb, Command* pc) {
        mButtons.push_back(pb);
        mCommands.push_back(pc);
    }

    size_t getNumberOfButtons() const { return mButtons.size(); }

    void draw() const {
        for (auto p : mButtons)
            p->draw();
    }

    void handleEvent(sf::Event event) {
        for (std::size_t i = 0; i < mButtons.size(); ++i) {
            if (mButtons.at(i)->handleEvent(event)) {
                mCommands.at(i)->execute();
                mHistory.push(mCommands.at(i));
            }
        }
    }

    ~ControlPanel() {
        for (auto p : mButtons)
            delete p;
        for (auto p : mCommands)
            delete p;
    }
};

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 800), "Shapes and Command", sf::Style::Default, settings);

    sf::Font font;
    // if (!font.loadFromFile("sourceCodePro.ttf")) {
    //     std::cerr << "Error. Can't load font" << std::endl;
    //     return 1;
    // }

    ShapePool pool(window, {300, 50}, {450, 700});
    pool.addShape(new sf::RectangleShape({getRandomFloat(50, 150), getRandomFloat(50, 150)}));
    pool.addShape(new sf::RectangleShape({getRandomFloat(50, 150), getRandomFloat(50, 150)}));
    pool.addShape(new sf::CircleShape(getRandomFloat(30, 100), 3));
    pool.addShape(new sf::CircleShape(getRandomFloat(30, 100)));
    pool.addShape(new sf::CircleShape(getRandomFloat(30, 100)));

    CommandHistory history;
    ControlPanel control(window, history);

    control.addButton(new Button(window, {40, 80, 240, 40}, font, "Rotate First"), new RotateCommand(pool, 0, 30));
    control.addButton(new Button(window, {40, 140, 240, 40}, font, "Rotate Second"), new RotateCommand(pool, 1, 45));
    control.addButton(new Button(window, {40, 200, 240, 40}, font, "One Random Color"), new RandomColorCommand(pool, 3));
    control.addButton(new Button(window, {40, 260, 240, 40}, font, "All Random Positions"), new RandomAllPositionsCommand(pool));
    control.addButton(new Button(window, {40, 320, 240, 40}, font, "New Random Shape"), new AddNewRandomShape(pool, 10, 150));
    control.addButton(new Button(window, {40, 380, 240, 40}, font, "Clear All"), new ClearAllShapesCommand(pool));
    control.addButton(new Button(window, {40, 440, 240, 40}, font, "Random All"), 
        new MultiCommand({
            new RandomAllColorsCommand(pool),
            new RandomAllPositionsCommand(pool)
        }));
    control.addButton(new Button(window, {40, 500, 240, 40}, font, "Random Colors"), new RandomAllColorsCommand(pool));
    control.addButton(new Button(window, {40, 560, 240, 40}, font, "Undo"), new UndoCommand(history));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            control.handleEvent(event);
        }

        window.clear(sf::Color::Black);
        pool.draw();
        control.draw();
        window.display();
    }

    return 0;
}