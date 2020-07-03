#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Dino.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(constants::k_screenWidth, constants::k_screenHeight), "Chrome Snake Game");

    Dino dino;

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

        dino.Render(window);

        window.display();
    }
    return 0;
}
