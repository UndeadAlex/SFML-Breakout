#include "Ball.h"
#include <SFML/System/Vector2.hpp>
#include "GameConstants.h"

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

	CheckBounds();
}

void Ball::Bounce(bool isLeft)
{
	mVelocity = isLeft ? LEFT_LAUNCH : RIGHT_LAUNCH;
}

bool Ball::CheckBounds()
{
	sf::Vector2f tmpPos = this->getPosition();

	const float TOP_SCREEN = this->getRadius() / 2;
	const float LEFT_SCREEN = -TOP_SCREEN;
	const float RIGHT_SCREEN = GameConstants::WINDOW_WIDTH - (this->getRadius() / 2);
	const float BOTT_SCREEN = GameConstants::WINDOW_HEIGHT - (this->getRadius() / 2);

	// Check Bounds
	if (tmpPos.x < LEFT_SCREEN || tmpPos.x > RIGHT_SCREEN)
	{
		mVelocity.x = -mVelocity.x;
	}
	if (tmpPos.y < TOP_SCREEN)
	{
		mVelocity.y = -mVelocity.y;
	}
	
	if (tmpPos.y > BOTT_SCREEN)
	{
		// Restart Game.
	}

	return false;
}