#include "Cactus.h"

void Cactus::Update()
{
	float x = getPosition().x;
	x -= m_speed;

	setPosition(x, constants::k_screenHeight - m_size);
}
