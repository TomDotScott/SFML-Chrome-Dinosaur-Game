#include "Dino.h"

#include <iostream>

Dino::Dino(const std::string& _fileName) : Entity(_fileName)
{
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

void Dino::Jump() {
	m_velocity.y = -m_jumpForce;
	// m_position += m_velocity;
}
