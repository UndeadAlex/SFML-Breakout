#include "Brick.h"

#include "GameRandom.h"

Brick::Brick()
{
	this->setPosition(0, 0);
	this->setSize({ 100,50 });
	this->setOutlineColor(sf::Color::Black);
	//this->setOutlineThickness(5.0f);
	this->setFillColor(GameRandom::RandomColor());
}

Brick::Brick(int x, int y, float width, float height)
{
	this->setPosition(x, y);
	this->setSize({ width,height });
	this->setOutlineColor(sf::Color::Black);
	//this->setOutlineThickness(5.0f);
	this->setFillColor(GameRandom::RandomColor());
}

Brick::Brick(sf::Vector2f position, sf::Vector2f size)
{
	this->setPosition(position);
	this->setSize(size);
	this->setOutlineColor(sf::Color::Black);
	//this->setOutlineThickness(5.0f);
	this->setFillColor(GameRandom::RandomColor());
}

Brick::~Brick()
{

}

void Brick::Update()
{

}
