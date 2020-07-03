#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Entity.h"

class Dino : public Entity {
public:
	explicit Dino(const std::string& _fileName);
	void Update();
	// void Render(sf::RenderWindow& _window) const override = 0;
private:
	void Jump();

	// going here because it's the only thing affected by it
	float m_gravity{ 0.75f };

	float m_size{ 50 };

	float m_jumpForce = 15;
	sf::Vector2f m_velocity{};
};

