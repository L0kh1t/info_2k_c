#include <iostream>
#include <cmath>

/*
    Вспомогательная структура Vector2f, которая описывает математический вектор в двумерном пространстве.
    Также написаны функции для удобной работы с этой структурой.
    Работает примерно также, как и класс sf::Vector2f из библиотеки SFML.
    (но подключать целую библиотеку только ради класса sf::Vector2f не стоит)
*/

struct Vector2f
{
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right)
{
    Vector2f result = {left.x + right.x, left.y + right.y};
    return result;
}

Vector2f operator*(Vector2f left, float right)
{
    Vector2f result = {left.x * right, left.y * right};
    return result;
}

Vector2f operator*(float left, Vector2f right)
{
    Vector2f result = {left * right.x, left * right.y};
    return result;
}

Vector2f& operator+=(Vector2f& left, Vector2f right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

float getDistance(Vector2f a, Vector2f b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

std::ostream& operator<<(std::ostream& out, Vector2f right)
{
    out << "(" << right.x << ", " << right.y << ")";
    return out;
}


class Shape {
protected:
    Vector2f mPosition;

public:
    Shape() : mPosition({0, 0}) {}
    Shape(Vector2f position) : mPosition(position) {}

    Vector2f getPosition() const {
        return mPosition;
    }

    void setPosition(Vector2f newPosition) {
        mPosition = newPosition;
    }

    void move(Vector2f change) {
        mPosition += change;
    }

    virtual float calculatePerimeter() const = 0; 
};

/*
    Классы Circle, Rectangle и Triangle, описывающие круг, прямоугольник и треугольник соответственно.
*/

class Circle : public Shape {
private:
    float mRadius;

public:
    Circle(float radius) : Shape(), mRadius(radius) {}

    float calculatePerimeter() const override {
        return 2 * 3.14159265 * mRadius;
    }
};

class Rectangle : public Shape {
private:
    float mWidth;
    float mHeight;

public:
    Rectangle(float width, float height) : Shape(), mWidth(width), mHeight(height) {}

    float calculatePerimeter() const override {
        return 2 * (mWidth + mHeight);
    }
};

class Triangle : public Shape {
private:
    Vector2f mPointA;
    Vector2f mPointB;
    Vector2f mPointC;

public:
    Triangle(Vector2f pointA, Vector2f pointB, Vector2f pointC) 
        : Shape(), mPointA(pointA), mPointB(pointB), mPointC(pointC) {}

    float calculatePerimeter() const override {
        return getDistance(mPointA, mPointB) + 
               getDistance(mPointB, mPointC) + 
               getDistance(mPointC, mPointA);
    }
};

int main()
{
    Circle a(10);
    std::cout << a.calculatePerimeter() << std::endl;

    Rectangle b(100, 200);
    std::cout << b.calculatePerimeter() << std::endl;

    Triangle c({5, 2}, {-7, 5}, {4, 4});
    std::cout << c.calculatePerimeter() << std::endl;
}