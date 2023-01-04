#pragma once
#include <array>
#include "Box.h"

const int SIZE = 5;
const int ARRAY_SIZE = SIZE * SIZE;
const int FIELD_SIZE = 450;
const int CELL_SIZE = 85;
const int COLOR_CELL_SIZE = 70;
const int PADDING = -100;

enum class Direction {
	Left = 0,
	Right = 1, 
	Up = 2,
	Down = 3
};


class Game :public sf::Drawable, public sf::Transformable
{
public:
	Game();
	void Init();
	bool Over();
	bool Check();
	void Move(Direction direction);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Font font;
	sf::Text text;
	std::array< std::unique_ptr<Box>, 3> box_colores;
	std::array<std::unique_ptr<Box>,ARRAY_SIZE> boxes;
	std::array<int,ARRAY_SIZE> elements= { TypeBox::Orange,TypeBox::Block,TypeBox::Yellow,TypeBox::Block,TypeBox::Orange,
		TypeBox::Red,TypeBox::Empty,TypeBox::Yellow,TypeBox::Empty,TypeBox::Orange,
		TypeBox::Yellow,TypeBox::Block,TypeBox::Red,TypeBox::Block,TypeBox::Red,
		TypeBox::Orange,TypeBox::Empty,TypeBox::Orange,TypeBox::Empty,TypeBox::Yellow,
		TypeBox::Red,TypeBox::Block,TypeBox::Red,TypeBox::Block,TypeBox::Yellow };
	int current_index;
	bool solved;
	void SetCell(const sf::String& name, int i) const;
};

