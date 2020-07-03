#pragma once
#include "Entity.h"

class Cactus final : public Entity{
public:
	explicit Cactus(const std::string& _fileName) : Entity(_fileName) { ResetPosition(); };
	
	void Update();

	float GetSize() const { return m_size; }
	
	bool IsVisible() const { return m_isVisible; }
	
	void MakeVisible();
	
private:
	void ResetPosition() { setPosition(constants::k_screenWidth + 100, constants::k_screenHeight - m_size); };
	
	bool m_isVisible = false;
	
	float m_size{ 50.f };
	float m_speed{ 8.f };
};

