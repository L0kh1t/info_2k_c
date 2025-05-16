#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <set>

class Observer {
public:
    virtual void update(float value) = 0;
    virtual ~Observer() = default;
};

class Subject {
public:
    virtual void addObserver(Observer* p) = 0;
    virtual void removeObserver(Observer* p) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

class Slider : public Drawable, public Subject {
protected:
    sf::RectangleShape mTrackShape;
    sf::RectangleShape mThumbShape;
    sf::Color mTrackColor{200, 200, 220};
    sf::Color mThumbColor{150, 150, 240};
    sf::RenderWindow& mRenderWindow;
    bool mIsPressed{false};
    std::set<Observer*> mObservers;
    bool mIsRotationSlider;

public:
    Slider(sf::RenderWindow& window, sf::Vector2f centerPosition, 
           sf::Vector2f trackSize, sf::Vector2f thumbSize, bool isRotationSlider)
        : mRenderWindow(window), mIsRotationSlider(isRotationSlider) {
        mTrackShape.setSize(trackSize);
        mTrackShape.setOrigin(trackSize / 2.0f);
        mTrackShape.setPosition(centerPosition);
        mTrackShape.setFillColor(mTrackColor);

        mThumbShape.setSize(thumbSize);
        mThumbShape.setOrigin(thumbSize / 2.0f);
        mThumbShape.setPosition(centerPosition);
        mThumbShape.setFillColor(mThumbColor);
    }

    void draw() const override {
        mRenderWindow.draw(mTrackShape);
        mRenderWindow.draw(mThumbShape);
    }

    void handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::MouseMoved && mIsPressed) {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
            float min = mTrackShape.getPosition().x - mTrackShape.getSize().x / 2.0f;
            float max = mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;
            mThumbShape.setPosition({std::clamp(mousePosition.x, min, max), mThumbShape.getPosition().y});
            notifyObservers();
        }
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (mThumbShape.getGlobalBounds().contains(mousePosition) || mTrackShape.getGlobalBounds().contains(mousePosition)) {
                mIsPressed = true;
                mThumbShape.setPosition({mousePosition.x, mThumbShape.getPosition().y});
                notifyObservers();
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            mIsPressed = false;
        }
    }

    float getValue() const {
        float part = mThumbShape.getPosition().x - mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;
        return part / mTrackShape.getSize().x * 100.0f;
    }

    void addObserver(Observer* p) override { mObservers.insert(p); }
    void removeObserver(Observer* p) override { mObservers.erase(p); }

    void notifyObservers() override {
        float value = getValue();
        for (auto p : mObservers) {
            p->update(value);
        }
    }
};

class Square : public Observer, public Drawable {
    sf::RectangleShape mShape;
    sf::RenderWindow& mRenderWindow;

public:
    Square(sf::RenderWindow& window, sf::Vector2f position, float size) 
        : mRenderWindow(window), mShape({size, size}) {
        mShape.setOrigin(size/2, size/2);
        mShape.setPosition(position);
        mShape.setFillColor(sf::Color::Red);
    }

    void draw() const override { mRenderWindow.draw(mShape); }

    void update(float value) override {
        mShape.setRotation(value * 3.6f);
    }
};

class ColorCircle : public Observer, public Drawable {
    sf::CircleShape mShape;
    sf::RenderWindow& mRenderWindow;

public:
    ColorCircle(sf::RenderWindow& window, sf::Vector2f position, float radius) 
        : mRenderWindow(window), mShape(radius) {
        mShape.setOrigin(radius, radius);
        mShape.setPosition(position);
        mShape.setFillColor(sf::Color::Green);
    }

    void draw() const override { mRenderWindow.draw(mShape); }

    void update(float value) override {
        mShape.setFillColor(sf::Color(0, static_cast<sf::Uint8>(value*2.55f), 0));
    }
};

class MovingCircle : public Observer, public Drawable {
    sf::CircleShape mShape;
    sf::RenderWindow& mRenderWindow;
    sf::Vector2f mOriginalPosition;

public:
    MovingCircle(sf::RenderWindow& window, sf::Vector2f position, float radius) 
        : mRenderWindow(window), mShape(radius), mOriginalPosition(position) {
        mShape.setOrigin(radius, radius);
        mShape.setPosition(position);
        mShape.setFillColor(sf::Color::Yellow);
    }

    void draw() const override { mRenderWindow.draw(mShape); }

    void update(float value) override {
        float newY = mOriginalPosition.y + (value - 50);
        mShape.setPosition({mOriginalPosition.x, newY});
    }
};

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 800), "Two Sliders", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    
    Slider rotationSlider(window, {200, 700}, {300, 20}, {20, 60}, true);  
    Slider colorSlider(window, {600, 700}, {300, 20}, {20, 60}, false);   

    std::vector<Observer*> observers = {
        new Square(window, {200, 300}, 80),       
        new ColorCircle(window, {600, 300}, 50),  
        new MovingCircle(window, {400, 300}, 40)  
    };

    rotationSlider.addObserver(observers[0]); 
    rotationSlider.addObserver(observers[2]); 
    colorSlider.addObserver(observers[1]);    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            rotationSlider.handleEvent(event);
            colorSlider.handleEvent(event);
        }

        window.clear(sf::Color::Black);
        rotationSlider.draw();
        colorSlider.draw();
        for (auto observer : observers) {
            dynamic_cast<Drawable*>(observer)->draw();
        }
        window.display();
    }

    for (auto observer : observers)
        delete observer;

    return 0;
}