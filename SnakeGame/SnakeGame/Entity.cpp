#include "Entity.h"

#include <iostream>

Entity::Entity(const std::string& _fileName)
{
	if(m_texture.loadFromFile("Resources/" + _fileName))
	{
		std::cout << "TEXTURE LOADED CORRECTLY" << std::endl;
	};
	setTexture(m_texture);
}

void Entity::Render(sf::RenderWindow& _window) const
{
	_window.draw(*this);
}
