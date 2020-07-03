#pragma once
#include "Entity.h"

class Cactus final : public Entity{
public:
	explicit Cactus(const std::string& _fileName) : Entity(_fileName)
	{
		setPosition(constants::k_screenWidth + 100, constants::k_screenHeight - m_size);
	};
	void Update();
private:
	float m_size{ 50.f };
	float m_speed{ 3.f };
};

