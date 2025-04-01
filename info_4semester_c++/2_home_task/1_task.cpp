#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Circle and space");
	window.setFramerateLimit(60);

	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(300, 200);

	//Сгътр р
	// while (window.isOpen())
	// {
	// 	sf::Event event;
	// 	while (window.pollEvent(event))
	// 	{
	// 		if (event.type == sf::Event::Closed)
	// 				window.close();
	// 	}
	
	// 	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	// 	{
	// 		circle.setFillColor(sf::Color::Red);
	// 	}
	// 	else
	// 	{
	// 		circle.setFillColor(sf::Color::Green);
	// 	}

	// 	window.clear();
	// 	window.draw(circle);
	// 	window.display();
	// }

	//Сѓътр с:

	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				circle.setFillColor(sf::Color::Red);
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				circle.setFillColor(sf::Color::Green);
			}

		}
 	
	window.clear();
 	window.draw(circle);
	window.display();
	}
	
	return 0;
}