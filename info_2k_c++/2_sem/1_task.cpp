#include "point.hpp"
using std::cout, std::endl;

class Circle {
	Point center;
	float radius;

public:
	Circle(const Point& x, float y)
	{
		center = x;
		radius = y;
	}
	Circle()
	{
		Point x;
		center = x;
		radius = 1;
	}
	Circle(const Circle& c)
	{
		center = c.center;
		radius = c.radius;
	}
	Point getCenter() const {return center;}
	float getRadius() const {return radius;}
	void setcenter(Point c) {this->center = c;}
	void setradius(float r) 
	{
		if (r < 0)
			r = 0;
		this->radius = r;
	}
	float area() const { return 3.14 * radius * radius; }
	float distance(const Point& p) const { return std::abs(center.distance(p) - radius); }
	bool isColliding(const Circle& c) const
	{
		if (center.distance(c.center) < radius + c.radius)
			return true;
		else
			return false;
	}
	void move(const Point& p)
	{
		center = center + p;
	}
};

int main()
{
	Point p = { 7, -1 };
	Point q = { -4, 2 };
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;

	
		Circle a({4, 1}, 3);
		Circle b;

		cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl;
		cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

		cout << "Area of a = " << a.area() << endl;
		cout << "Distance from point p to circle a = " << a.distance(p) << endl;


		cout << "Collisions:" << endl;
		if (a.isColliding(b))
			cout << "Yes, a is colliding b" << endl;
		else
			cout << "No, a isn't colliding b" << endl;


		cout << "Moving b by {1, 1}:" << endl;
		b.move({1, 1});
		if (a.isColliding(b))
			cout << "Yes, a is colliding b" << endl;
		else
			cout << "No, a isn't colliding b" << endl;
	
}