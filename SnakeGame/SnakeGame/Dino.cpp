#include "Dino.h"

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
	sf::RectangleShape rect({ m_size, m_size });
	rect.setPosition(m_position);
	_window.draw(rect);
}

void Dino::Jump() {
	m_velocity.y = -m_jumpForce;
	// m_position += m_velocity;
}
