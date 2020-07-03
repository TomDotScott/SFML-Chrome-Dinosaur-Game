#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"

class Dino {
public:
	void Update();
	void Render(sf::RenderWindow& _window);
private:
	void Jump();

	sf::Vector2f m_position{ 50, constants::k_screenHeight - 50 };

	// going here because it's the only thing affected by it
	float m_gravity{ 0.5f };

	float m_size{ 50 };

	float m_jumpForce = 15;
	sf::Vector2f m_velocity{};
};

