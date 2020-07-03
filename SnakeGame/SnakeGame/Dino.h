#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"

class Dino {
public:
	void Render(sf::RenderWindow& _window);

private:
	sf::Vector2f m_position{50, constants::k_screenHeight - 50};
};

