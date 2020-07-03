#include "Dino.h"

#include <iostream>

Dino::Dino()
{
	if(m_texture.loadFromFile("Resources/dino.png"))
	{
		std::cout << "TEXTURE LOADED" << std::endl;
	}
	
	m_sprite.setTexture(m_texture);
}

void Dino::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		Jump();
	}

	m_velocity.y += m_gravity;
	m_position += m_velocity;

	// constrain the value of y to make the dino on screen
	if (m_position.y >= constants::k_screenHeight - m_size) {
		m_position.y = constants::k_screenHeight - m_size;
	}
}

void Dino::Render(sf::RenderWindow& _window) {
	// sf::RectangleShape rect({ m_size, m_size });
	// rect.setPosition(m_position);
	m_sprite.setPosition(m_position);
	_window.draw(m_sprite);
}

void Dino::Jump() {
	m_velocity.y = -m_jumpForce;
	// m_position += m_velocity;
}
