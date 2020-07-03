#include "Entity.h"

Entity::Entity(const std::string& _fileName)
{
	m_texture.loadFromFile("Resources/" + _fileName);
	setTexture(m_texture);
}

void Entity::Render(sf::RenderWindow& _window) const
{
	_window.draw(*this);
}
