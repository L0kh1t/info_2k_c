#pragma once
#include <cmath>
#include <iostream>

class Vector2f
{
public:
	float x;
	float y;
};

Vector2f operator+(Vector2f a, Vector2f b)
{
    Vector2f result = { a.x + b.x, a.y + b.y };
    return result;
}

Vector2f operator-(Vector2f a, Vector2f b)
{
    Vector2f result = { a.x - b.x, a.y - b.y };
    return result;
}

Vector2f operator*(Vector2f a, float b)
{
    Vector2f result = { a.x*b, a.y*b };
    return result;
}

float operator*(Vector2f a, Vector2f b)
{
    float result = a.x*b.x + a.y * b.y;
    return result;
}

Vector2f operator-(Vector2f a)
{
    Vector2f result;
    result.x = -a.x;
    result.y = -a.y;
    return result;
}

Vector2f operator+(Vector2f a)
{
    return a;
}

bool operator==(Vector2f a, Vector2f b)
{
    if (a.x == b.x && a.y == b.y)
        return true;
    else
        return false;
}

bool operator!=(Vector2f a, Vector2f b)
{
    if (a.x != b.x || a.y != b.y)
        return true;
    else
        return false;
}

Vector2f& operator-=(Vector2f& a, const Vector2f b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vector2f& operator*=(Vector2f& a, const float b)
{
    a.x *= b;
    a.y += b;
    return a;
}

Vector2f& operator/=(Vector2f& a, const float b)
{
    a.x /= b;
    a.y /= b;
    return a;
}

Vector2f& operator+=(Vector2f& a, Vector2f b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

std::ostream& operator<<(std::ostream& out, Vector2f a)
{
    out << " (" << a.x << "," << a.y << ") ";
    return out;
}

std::istream& operator>>(std::istream& in, Vector2f& c)
{
    in >> c.x >> c.y;
    return in;
}
