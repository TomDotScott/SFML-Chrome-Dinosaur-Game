#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Dino.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(constants::k_screenWidth, constants::k_screenHeight), "Chrome Snake Game");
    window.setFramerateLimit(60);
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
    	
        dino.Update();
        dino.Render(window);

        window.display();
    }
    return 0;
}
