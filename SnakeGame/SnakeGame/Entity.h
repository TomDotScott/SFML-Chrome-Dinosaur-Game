#pragma once
#include "SFML/Graphics.hpp"

class Entity : public sf::Sprite
{
public:
	explicit Entity(const std::string& _fileName);
	virtual void Render(sf::RenderWindow& _window) const;

private:
	sf::Texture m_texture;
};
