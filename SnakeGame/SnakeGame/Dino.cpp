#include "Dino.h"
#include <iostream>

Dino::Dino(const std::string& _fileName) : Entity(_fileName) {
	sf::Texture texture;
	texture.loadFromFile("Resources/dino_1.png");
	m_frames.emplace_back(texture);
	texture.loadFromFile("Resources/dino_2.png");
	m_frames.emplace_back(texture);
	texture.loadFromFile("Resources/dino_jump.png");
	m_frames.emplace_back(texture);
	texture.loadFromFile("Resources/dino_dead.png");
	m_frames.emplace_back(texture);

	setPosition({ 50, constants::k_screenHeight - 50 });
}

void Dino::Update() {
	Animate();

	if (getPosition().y == constants::k_screenHeight - m_size) {
		m_isOnGround = true;
	}

	if (m_isOnGround) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			Jump();
			m_isOnGround = false;
		}
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
		setTexture(m_frames[3]);
		m_isDead = true;
	}
}

void Dino::Jump() {
	m_velocity.y = -m_jumpForce;
}

void Dino::Animate()
{
	if (m_isOnGround && !m_isDead) {
		if (m_currentFrame == 2) {
			m_currentFrame = 0;
		}
		if (m_clock.getElapsedTime().asMilliseconds() >= 250) {
			m_currentFrame++;
			m_clock.restart();
		}

		setTexture(m_frames[m_currentFrame]);
	}else if(!m_isOnGround)
	{
		setTexture(m_frames[2]);
	}
}
