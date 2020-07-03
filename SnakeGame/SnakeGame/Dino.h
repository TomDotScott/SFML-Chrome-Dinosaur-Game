#pragma once
#include "Cactus.h"
#include "Entity.h"

class Dino final : public Entity {
public:
	explicit Dino(const std::string& _fileName);
	void Update();
	
	void CheckCollisions(const std::vector<Cactus>& _cacti);

	bool Dead() const { return m_isDead; }
	
private:
	void Jump();

	void Animate();

	sf::Clock m_clock;
	
	// going here because it's the only thing affected by it
	float m_gravity{ 0.75f };

	bool m_isDead{ false };
	bool m_isOnGround{ true };
	
	std::vector<sf::Texture> m_frames;
	
	float m_size{ 50 };

	int m_currentFrame{0};

	float m_jumpForce = 15;

	sf::Vector2f m_velocity{};
};

