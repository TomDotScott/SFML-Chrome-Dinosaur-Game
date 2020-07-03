#include "Dino.h"
#include <iostream>

Dino::Dino(const std::string& _fileName) : Entity(_fileName) {
	setPosition({ 50, constants::k_screenHeight - 50 });
}

void Dino::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		Jump();
	}

	m_velocity.y += m_gravity;

	sf::Vector2f currentPos = getPosition();
	currentPos += m_velocity;

	// constrain the value of y to make the dino on screen
	if (currentPos.y >= constants::k_screenHeight - m_size) {
		currentPos.y = constants::k_screenHeight - m_size;
	}

	setPosition(currentPos);
}

void Dino::CheckCollisions(const std::vector<Cactus>& _cacti)
{
	bool isOverlapping{ false };
	const sf::Vector2f dinoPosition = getPosition();
	for (const auto& cactus : _cacti) {
		if (cactus.IsVisible()) {
			const sf::Vector2f cactusPosition = cactus.getPosition();
			// 2-D AABB collision check
			if ((dinoPosition.x < cactusPosition.x + cactus.GetSize()) &&
				(cactusPosition.x < dinoPosition.x + m_size) &&
				(dinoPosition.y < cactusPosition.y + cactus.GetSize()) &&
				(cactusPosition.y < dinoPosition.y + m_size)) {
				isOverlapping = true;
				std::cout << "COLLISION OCCURED!" << std::endl;
			}
		}
	}

	if(isOverlapping)
	{
		m_isDead = true;
	}
}

void Dino::Jump() {
	// only jump if on the ground
	if (getPosition().y == constants::k_screenHeight - m_size) {
		m_velocity.y = -m_jumpForce;
	}
	// m_position += m_velocity;
}
