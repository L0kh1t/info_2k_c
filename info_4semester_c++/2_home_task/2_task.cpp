#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rectangle and Mouse");
    sf::RectangleShape rectangle(sf::Vector2f(300, 200));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(200, 200);

    while (window.isOpen())
    {
        //пункт а
        // sf::Event event;
        // while (window.pollEvent(event))
        // {
        //     if (event.type == sf::Event::Closed)
        //         window.close();
            
        //     if (event.type == sf::Event::Resized)
        //     {
        //         sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        //         window.setView(sf::View(visibleArea));
        //     }
        // }

        // sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
        
        // if (rectangle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_position)))
        // {
        //     rectangle.setFillColor(sf::Color::Red);
        // }
        // else
        // {
        //     rectangle.setFillColor(sf::Color::Green);
        // }

        // window.clear();
        // window.draw(rectangle);
        // window.display();

        //пункт б
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            
            if (event.type == sf::Event::MouseMoved)
            {
                if (rectangle.getGlobalBounds().contains(
                    static_cast<sf::Vector2f>(sf::Vector2i(event.mouseMove.x, event.mouseMove.y))))
                {
                    rectangle.setFillColor(sf::Color::Red);
                }
                else
                {
                    rectangle.setFillColor(sf::Color::Green);
                }
            }
        }

        window.clear();
        window.draw(rectangle);
        window.display();

    }

    return 0;
}