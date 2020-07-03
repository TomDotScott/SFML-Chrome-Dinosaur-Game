#pragma once
#include "Cactus.h"
#include "Entity.h"

class Dino final : public Entity {
public:
	explicit Dino(const std::string& _fileName);
	void Update();
	
	void CheckCollisions(const std::vector<Cactus>& _cacti);
private:
	void Jump();

	bool m_isDead;

	// going here because it's the only thing affected by it
	float m_gravity{ 0.75f };

	float m_size{ 50 };

	float m_jumpForce = 15;
	sf::Vector2f m_velocity{};
};

