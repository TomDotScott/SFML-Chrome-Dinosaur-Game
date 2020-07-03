#include <SFML/Graphics.hpp>
#include "Cactus.h"
#include "Constants.h"
#include "Dino.h"

int random_range(const int _min, const int _max) {
	return _min + rand() % ((_max + 1) - _min);
}

int main() {
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(constants::k_screenWidth, constants::k_screenHeight), "Chrome Snake Game");
	window.setFramerateLimit(60);
	Dino dino("dino_1.png");

	// basic object pooling
	std::vector<Cactus> cactiPool;
	cactiPool.reserve(10);
	for (int i = 0; i < 10; i++) {
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

		if(random_range(1, 100) <= 3)
		{
			int index = random_range(0, cactiPool.size() - 1);
			if (!cactiPool[index].IsVisible()) {
				cactiPool[index].MakeVisible();
			}
		}
		
		window.clear(sf::Color::White);

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

		window.display();
	}
	return 0;
}
