#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cactus.h"
#include "Constants.h"
#include "Dino.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(constants::k_screenWidth, constants::k_screenHeight), "Chrome Snake Game");
    window.setFramerateLimit(60);
    Dino dino("dino.png");
    std::vector<Cactus> cacti;

    cacti.emplace_back("cactus.png");

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

        window.clear(sf::Color::White);

    	for(auto& cactus : cacti)
    	{
            cactus.Update();
            cactus.Render(window);
    	}
    	
        dino.Update();

        dino.CheckCollisions(cacti);
    	
        dino.Render(window);

        window.display();
    }
    return 0;
}
