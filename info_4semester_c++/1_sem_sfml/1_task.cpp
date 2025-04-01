#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Square!", sf::Style::Default);
	window.setFramerateLimit(60);
	
	sf::RectangleShape squar;
	squar.setSize(sf::Vector2f{ 100, 100 });
	squar.setPosition(sf::Vector2f{200, 200 });
	squar.setFillColor(sf::Color::Green);

	squar.setOrigin(squar.getSize().x / 2.f, squar.getSize().y / 2.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		squar.rotate(2);

		window.clear(sf::Color::Black);
		window.draw(squar);
		window.display();
	}

}