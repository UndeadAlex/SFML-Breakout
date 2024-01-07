#include "Paddle.h"
#include <SFML/Window/Mouse.hpp>

Paddle::Paddle()
{
	this->setPosition(0, 0);
	this->setSize({ 100,10 });
	this->setOrigin(this->getSize() / 2.0f);
}
Paddle::Paddle(int x, int y, float width, float height)
{
	this->setPosition(x, y);
	this->setSize({ width,height });
	this->setOrigin(this->getSize() / 2.0f);
}
Paddle::Paddle(sf::Vector2f position, sf::Vector2f size)
{
	this->setPosition(position);
	this->setSize(size);
	this->setOrigin(this->getSize() / 2.0f);
}
Paddle::~Paddle()
{

}

void Paddle::Update()
{
	float mouseX = sf::Mouse::getPosition().x;
	this->setPosition(mouseX, this->getPosition().y);
}
