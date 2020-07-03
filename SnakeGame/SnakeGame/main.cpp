#include <SFML/Graphics.hpp>
#include "Cactus.h"
#include "Constants.h"
#include "Dino.h"
#include "SoundManager.h"

int random_range(const int _min, const int _max) {
	return _min + rand() % ((_max + 1) - _min);
}

int main() {
	srand(time(nullptr));

	sf::Font font;
	font.loadFromFile("Resources/gamefont.ttf");
	sf::Text scoreText("Score: ", font, 20);

	
	sf::RenderWindow window(sf::VideoMode(constants::k_screenWidth, constants::k_screenHeight), "Chrome Snake Game");
	window.setFramerateLimit(60);
	Dino dino("dino_1.png");

	sf::Clock clock{};
	
	int score{ 0 };
	
	// basic object pooling
	std::vector<Cactus> cactiPool;
	cactiPool.reserve(5);
	for (int i = 0; i < 5; i++) {
		cactiPool.emplace_back("cactus.png");
	}

	while (window.isOpen()) {
		sf::Event event{};
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		if (!dino.Dead()) {
			if (clock.getElapsedTime().asMilliseconds() >= 100) {
				score += 1;
				if(score % 100 == 0)
				{
					SoundManager::Instance().PlaySFX("100");
				}
				clock.restart();
			}
		}
		
		window.clear(sf::Color::White);


		if (random_range(1, 100) <= 2) {
			int index = random_range(0, cactiPool.size() - 1);
			if (!cactiPool[index].IsVisible()) {
				cactiPool[index].MakeVisible();
			}
		}
		
		for (auto& cactus : cactiPool) {
			if (cactus.IsVisible()) {
				if (!dino.Dead()) {
					cactus.Update();
				}
				cactus.Render(window);
			}
		}

		if (!dino.Dead()) {
			dino.Update();

			dino.CheckCollisions(cactiPool);
		}

		dino.Render(window);

		scoreText.setString("Score: " + std::to_string(score));
		scoreText.setFillColor({ 0, 0, 0 });
		scoreText.setPosition(constants::k_screenWidth - scoreText.getGlobalBounds().width - 10, 10);
		window.draw(scoreText);
		
		window.display();
	}
	return 0;
}
