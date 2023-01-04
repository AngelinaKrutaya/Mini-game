#pragma once
#include <SFML/Graphics.hpp>

enum TypeBox {
	Empty = 0,
	Yellow = 1,
	Orange = 2,
	Red = 3,
	Block = 4
};

class Box
{
public:
	Box();

	void SetImage(const sf::String& file_name);
	void SetPosition(int x, int y);
	sf::Sprite& GetSprite();

private:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
};

