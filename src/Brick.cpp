#include "Brick.h"

#include "GameRandom.h"

Brick::Brick()
{
	this->setPosition(0, 0);
	this->setSize({ 100,50 });
	this->setFillColor(GameRandom::RandomColor());
}

Brick::Brick(int x, int y, float width, float height)
{
	this->setPosition(x, y);
	this->setSize({ width,height });
	this->setFillColor(GameRandom::RandomColor());
}

Brick::Brick(sf::Vector2f position, sf::Vector2f size)
{
	this->setPosition(position);
	this->setSize(size);
	this->setFillColor(GameRandom::RandomColor());
}

Brick::Brick(sf::Vector2f position, sf::Vector2f size, sf::Color brickColor)
{
	this->setPosition(position);
	this->setSize(size);
	this->setFillColor(brickColor);
}

Brick::Brick(int x, int y, float width, float height, sf::Color brickColor)
{
	this->setPosition(x, y);
	this->setSize({ width,height });
	this->setFillColor(brickColor);
}

Brick::~Brick()
{

}

void Brick::Update()
{

}
