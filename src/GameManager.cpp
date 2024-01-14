#include "GameManager.h"

#include <stdio.h>
#include <sstream>
#include <SFML/Window/Mouse.hpp>
#include "GameRandom.h"

GameManager::GameManager(sf::RenderWindow& window) : mRenderWindow(window)
{
	if (!stdFont.loadFromFile("assets/fonts/FFFFORWA.TTF"))
	{
		printf("Failed to load FFF Forward, trying to load arial instead.");
		stdFont.loadFromFile("arial.ttf");
	}
	scoreText.setFont(stdFont);
	UpdateScoreText();

	// TODO: Set the ball radius to be different for increased res. e.g. playing the game at 1080p the ball and paddle don't scale. maybe using a % of the screen res to determine size ?
	mBall.setRadius(10.0f);
}

GameManager::~GameManager()
{

}

void GameManager::Init(bool resetStats)
{
	if (resetStats)
	{
		score = 0;
		UpdateScoreText();
	}

	mPaddle.setPosition(GameConstants::WINDOW_WIDTH / 2, GameConstants::WINDOW_HEIGHT - (mPaddle.getLocalBounds().height + 15));
	mBall.setPosition(GameConstants::WINDOW_WIDTH / 2, (BRICK_AREA.top + BRICK_AREA.height) + 50);

	// Set score text position.
	scoreText.setPosition(10, 10);
	scoreText.setCharacterSize(24);

	//mBricks.resize(NUM_PER_ROW * ROWS);
	mBricks.clear(); // For restart make sure previous bricks are gone :)
	for (int y = 0; y < ROWS; y++)
	{
		sf::Color rowColor = GameRandom::RandomColor();
		for (int x = 0; x < NUM_PER_ROW; x++)
		{
			int xSize = BRICK_AREA.width / NUM_PER_ROW;
			int ySize = BRICK_AREA.height / ROWS;

			// now technically speaking, this leaves the bricks 1px off perfect center, because odd numbers :)
			mBricks.push_back(Brick((xSize * x)+BRICK_AREA.left+ (BRICK_IN_PADDING/2), (ySize * y) + BRICK_AREA.top+ (BRICK_IN_PADDING / 2), xSize- BRICK_IN_PADDING, ySize- BRICK_IN_PADDING, rowColor));
		}
	}
}

void GameManager::Update(sf::Time& worldTime)
{
	if (mBricks.size() <= 0)
		Init(false);

	sf::Vector2i mousePos = sf::Mouse::getPosition(mRenderWindow);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mBall.setPosition((sf::Vector2f)mousePos);
	}

	
	mPaddle.MovePaddle((sf::Vector2f)mousePos);
	mBall.Update();

	HandleCollisions();
}

void GameManager::Render()
{
	mRenderWindow.draw(mBall);
	mRenderWindow.draw(mPaddle);



	for (auto& brick : mBricks)
	{
		mRenderWindow.draw(brick);
	}

	mRenderWindow.draw(scoreText);

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
	if (mBall.getPosition().y > GameConstants::WINDOW_HEIGHT)
		Init(true); // calling this to restart the game if they miss the ball, its mean buttttt :) 

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

			score++;
			UpdateScoreText();

			return; // this return hopefully should save some time, as long it isn't called at the end of the loop xD
		}
	}
}

void GameManager::UpdateScoreText()
{
	std::stringstream ss;
	ss << "Score: " << score;
	scoreText.setString(ss.str());
}

