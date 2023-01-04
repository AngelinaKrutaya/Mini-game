#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Game");
	Game game;
	game.setPosition(250.f, 250.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.key.code == sf::Keyboard::Escape) window.close();

			if (event.type == sf::Event::KeyPressed && !game.Over()) {
				if (event.key.code == sf::Keyboard::Left) game.Move(Direction::Left);
				if (event.key.code == sf::Keyboard::Right) game.Move(Direction::Right);
				if (event.key.code == sf::Keyboard::Up) game.Move(Direction::Up);
				if (event.key.code == sf::Keyboard::Down) game.Move(Direction::Down);
			}
		}
		window.clear();
		window.draw(game);
		window.display();
	}

	return 0;
}