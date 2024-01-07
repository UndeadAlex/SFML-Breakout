#include "Ball.h"
#include <SFML/System/Vector2.hpp>

Ball::Ball()
{
	this->setPosition(0, 0);
	this->setRadius(15.0f);
	this->setOrigin(this->getRadius(), this->getRadius());

	mVelocity = sf::Vector2f(0, 1);
}

Ball::Ball(int x, int y, float radius)
{
	this->setPosition(x, y);
	this->setRadius(radius);
	this->setOrigin(this->getRadius(), this->getRadius());

	mVelocity = sf::Vector2f(0, 1);
}

Ball::Ball(sf::Vector2f position, float radius)
{
	this->setPosition(position);
	this->setRadius(radius);
	this->setOrigin(this->getRadius(), this->getRadius());

	mVelocity = sf::Vector2f(0, 1);
}

Ball::~Ball()
{

}

void Ball::Update()
{
	this->setPosition(this->getPosition() + mVelocity);
}

void Ball::Bounce(bool isLeft)
{
	mVelocity = isLeft ? LEFT_LAUNCH : RIGHT_LAUNCH;
}
