#include "GameManager.h"

#include <stdio.h>
#include <SFML/Window/Mouse.hpp>

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

void GameManager::Init()
{
	mPaddle.setPosition(GameConstants::WINDOW_WIDTH / 2, GameConstants::WINDOW_HEIGHT - (mPaddle.getLocalBounds().height + 15));
	mBall.setPosition(GameConstants::WINDOW_WIDTH / 2, (BRICK_AREA.top + BRICK_AREA.height) + 50);

	//mBricks.resize(NUM_PER_ROW * ROWS);
	for (int y = 0; y < ROWS; y++)
	for (int x = 0; x < NUM_PER_ROW; x++)
	{
		int xSpacing = BRICK_AREA.width / NUM_PER_ROW;
		int ySpacing = BRICK_AREA.height / ROWS;

		mBricks.push_back(Brick((xSpacing * x)+BRICK_AREA.left, (ySpacing * y) + BRICK_AREA.top, xSpacing, ySpacing));
	}
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


	for (auto& brick : mBricks)
	{
		renderWindow.draw(brick);
	}


//#if _DEBUG
//	sf::RectangleShape originShape({ 10,10 });
//	originShape.setOrigin(5, 5);
//	originShape.setFillColor(sf::Color::Transparent);
//	originShape.setOutlineColor(sf::Color::Red);
//	originShape.setOutlineThickness(1.0f);
//
//	originShape.setPosition(GameConstants::WINDOW_WIDTH/2, (BRICK_AREA.top + BRICK_AREA.height));
//	renderWindow.draw(originShape);
//#endif
}

void GameManager::HandleCollisions()
{
	if (mBall.getGlobalBounds().intersects(mPaddle.getGlobalBounds()))
	{
		bool isLeftSide = (mBall.getPosition().x - mPaddle.getPosition().x) <= 0;
		mBall.Bounce(isLeftSide);
		printf("Ball hit paddle! %d\n", isLeftSide);
		return; // Can return to save on some calculations. (really i cant imagine one frame means anything but i hope)
	}

	for (int i = 0; i < mBricks.size(); i++)
	{
		if (mBricks[i].getGlobalBounds().intersects(mBall.getGlobalBounds()))
		{
			bool isLeftSide = (mBall.getPosition().x - (mBricks[i].getPosition().x + (mBricks[i].getSize().x/2)) <= 0);
			mBall.Bounce(isLeftSide);

			mBricks.erase(mBricks.begin() + i);
			printf("Ball hit brick!\n");
			return;
		}
	}
}

