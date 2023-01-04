#include "Box.h"

Box::Box()
{
}

void Box::SetImage(const sf::String& file_name)
{
	image.loadFromFile(file_name);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

void Box::SetPosition(int x, int y)
{
	sprite.setPosition(x, y);
}

sf::Sprite& Box::GetSprite()
{
	return sprite;
}
