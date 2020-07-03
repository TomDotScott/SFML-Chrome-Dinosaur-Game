#include "Dino.h"

void Dino::Render(sf::RenderWindow& _window)
{
	sf::RectangleShape rect({ 50, 50 });
	rect.setPosition(m_position);
	_window.draw(rect);
}
