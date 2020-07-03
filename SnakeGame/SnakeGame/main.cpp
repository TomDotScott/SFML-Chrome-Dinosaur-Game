#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chrome Snake Game");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    std::cout << "SnakeGame: Starting" << std::endl;

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
          switch(event.type)
          {
            case sf::Event::Closed:
              window.close();
            break;
            default:
              break;
          }
        }

        window.clear();

        window.draw(shape);

        window.display();
    }
    return 0;
}
