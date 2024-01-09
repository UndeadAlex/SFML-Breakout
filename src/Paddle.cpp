#include "Paddle.h"

#include <SFML/Window/Mouse.hpp>
#include "GameConstants.h"

#include <stdio.h>
#include <SFML/Graphics/RenderWindow.hpp>

Paddle::Paddle()
{
	this->setPosition(0, 0);
	this->setSize({ 200,20 });
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

void Paddle::MovePaddle(sf::Vector2f pos)
{
	float newX = GameConstants::ClampFloat(pos.x, this->getSize().x/2, GameConstants::WINDOW_WIDTH - (this->getSize().x/2));
	this->setPosition(newX, this->getPosition().y);
}
