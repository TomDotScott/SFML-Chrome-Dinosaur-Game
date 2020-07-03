#include "Cactus.h"

void Cactus::Update() {
	if (m_isVisible) {
		float x = getPosition().x;
		x -= m_speed;
		setPosition(x, constants::k_screenHeight - m_size);
	}
	if (getPosition().x <= 0) {
		m_isVisible = false;
	}
}

void Cactus::MakeVisible() {
	m_isVisible = true;
	ResetPosition();
}
