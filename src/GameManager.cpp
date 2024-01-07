#include "GameManager.h"

#include <stdio.h>
#include <SFML/Window/Mouse.hpp>
#include "GameConstants.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

void GameManager::Init()
{
	mPaddle.setPosition(GameConstants::WINDOW_WIDTH / 2, GameConstants::WINDOW_HEIGHT - 25);
	mBall.setPosition(GameConstants::WINDOW_WIDTH / 2, GameConstants::WINDOW_HEIGHT / 2);
}

void GameManager::Update(sf::Time& worldTime)
{
	/*sf::Vector2i mPos = sf::Mouse::getPosition();
	mBall.setPosition(sf::Vector2f(mPos));*/
	mPaddle.Update();
	mBall.Update();

	HandleCollisions();
}

void GameManager::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(mBall);
	renderWindow.draw(mPaddle);


//#if _DEBUG
//	sf::RectangleShape originShape({ 10,10 });
//	originShape.setOrigin(5, 5);
//	originShape.setFillColor(sf::Color::Transparent);
//	originShape.setOutlineColor(sf::Color::Red);
//	originShape.setOutlineThickness(1.0f);
//
//	originShape.setPosition(mBall.getPosition());
//	renderWindow.draw(originShape);
//
//
//	originShape.setPosition(mPaddle.getPosition());
//	renderWindow.draw(originShape);
//#endif
}

void GameManager::HandleCollisions()
{
	if (mBall.getGlobalBounds().intersects(mPaddle.getGlobalBounds()))
	{
		bool isLeftSide = (mBall.getPosition().x - mPaddle.getPosition().x) <= 0;
		mBall.Bounce(isLeftSide);
		printf("Ball hit me! %d\n", isLeftSide);
	}
}

