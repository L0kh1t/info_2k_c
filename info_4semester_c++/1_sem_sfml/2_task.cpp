#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>

struct Ball {
	sf::Vector2f position;
	sf::Vector2f velocity;
	float mass;
	float charge;
	float radius;
	sf::Color color;
	sf::CircleShape;
};

sf::Vector2f calculatePower(const Ball& ball1, const Ball& ball2)
{
	const float mindist = 10.0f;

	float distance = std::sqrt((ball1.position.x - ball2.position.x) * (ball1.position.x - ball2.position.x) + (ball2.position.y - ball1.position.y) * (ball2.position.y - ball1.position.y));
	sf::Vector2f direction = (ball2.position - ball1.position)/distance;

	if (distance < mindist) :
		return sf::Vector2f(0.0f, 0.0f);
	else:
		 return direction*ball1.charge * ball2.charge / (ditance * distanc);

}

int main()
{

}