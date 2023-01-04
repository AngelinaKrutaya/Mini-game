#include "Game.h"

Game::Game()
{
	Init();
	solved = false;
	current_index = 0;
}

void Game::Init()
{
	font.loadFromFile("calibri.ttf");
	text = sf::Text("Game over!", font, 50);
	text.setFillColor(sf::Color::Cyan);
	text.setPosition(200.f, 200.f);

	for (auto& box: boxes) 
		box = std::make_unique<Box>();

	for (auto& color : box_colores) 
		color = std::make_unique<Box>();
	
	(*box_colores[0]).SetImage("images/Color1.png");
	(*box_colores[1]).SetImage("images/Color2.png");
	(*box_colores[2]).SetImage("images/Color3.png");
	(*box_colores[0]).SetPosition(0 % SIZE * CELL_SIZE, 0 / SIZE * CELL_SIZE + PADDING);
	(*box_colores[1]).SetPosition(2 % SIZE * CELL_SIZE, 2 / SIZE * CELL_SIZE + PADDING);
	(*box_colores[2]).SetPosition(4 % SIZE * CELL_SIZE, 4 / SIZE * CELL_SIZE + PADDING);
}

bool Game::Over()
{
	return solved;
}

bool Game::Check()
{
	for (unsigned int i = 0; i < ARRAY_SIZE; i += SIZE)
		if (elements[i] != TypeBox::Yellow) return false;
	for (unsigned int i = 2; i < ARRAY_SIZE; i += SIZE)
		if (elements[i] != TypeBox::Orange) return false;
	for (unsigned int i = 4; i < ARRAY_SIZE; i += SIZE)
		if (elements[i] != TypeBox::Red) return false;
	return true;
}

void Game::Move(Direction direction)
{
	int move_index = -1;
	int col = current_index % SIZE;
	int row = current_index / SIZE;

	if (direction == Direction::Right && col < (SIZE - 1)) move_index = current_index + 1;
	if (direction == Direction::Left && col > 0) move_index = current_index - 1;
	if (direction == Direction::Down && row < (SIZE - 1)) move_index = current_index + SIZE;
	if (direction == Direction::Up && row > 0) move_index = current_index - SIZE;

	if (move_index >= 0) {
		if (elements[move_index] == TypeBox::Empty && elements[current_index] != TypeBox::Empty && elements[current_index] != TypeBox::Block) {
			int tmp = elements[current_index];
			elements[current_index] = elements[move_index];
			elements[move_index] = tmp;
		}
		current_index = move_index;
	}
	solved = Check();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	states.transform *= getTransform();

	for (unsigned int i = 0; i < ARRAY_SIZE; i++) {
		int x = i % SIZE * CELL_SIZE;
		int y = i / SIZE * CELL_SIZE;

		switch (elements[i]) {
		case TypeBox::Empty:
			SetCell("images/EmptyBox.png", i);
			break;
		case TypeBox::Yellow:
			SetCell("images/YellowBox.png", i);
			break;
		case TypeBox::Orange:
			SetCell("images/OrangeBox.png", i);
			break;
		case TypeBox::Red:
			SetCell("images/RedBox.png", i);
			break;
		case TypeBox::Block:
			SetCell("images/BlockBox.png", i);
			break;
		default:
			break;
		}

		for (auto& color : box_colores)
			target.draw((*color).GetSprite(), states);
		target.draw((*boxes[i]).GetSprite(), states);
		if (solved)
			target.draw(text, states);
	}
}

void Game::SetCell(const sf::String& name, int i) const
{
	int x = i % SIZE * CELL_SIZE;
	int y = i / SIZE * CELL_SIZE;
	(*boxes[i]).SetImage(name);
	(*boxes[i]).SetPosition(x, y);
	if (i == current_index)
		(*boxes[i]).GetSprite().setColor(sf::Color(255, 255, 255, 100));
	else
		(*boxes[i]).GetSprite().setColor(sf::Color(255, 255, 255, 255));
}
