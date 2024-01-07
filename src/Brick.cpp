#include "Brick.h"

Brick::Brick()
{
	this->setPosition(0, 0);
	this->setSize({ 100,50 });
}

Brick::Brick(int x, int y, float width, float height)
{
	this->setPosition(x, y);
	this->setSize({ width,height });
}

Brick::Brick(sf::Vector2f position, sf::Vector2f size)
{
	this->setPosition(position);
	this->setSize(size);
}

Brick::~Brick()
{

}

void Brick::Update()
{

}
