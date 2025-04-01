#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

sf::Color getRandomColor()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<uint8_t> d(0, 255);
    return sf::Color{d(gen), d(gen), d(gen)};
}

int main()

{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circles");
    window.setFramerateLimit(60);

    std::vector<sf::CircleShape> circles;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if 
    }
}