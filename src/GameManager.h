#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

#include "GameConstants.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

const int BRICK_OUT_PADDING = 50;
const int BRICK_IN_PADDING = 5;
const sf::IntRect BRICK_AREA (BRICK_OUT_PADDING, BRICK_OUT_PADDING, GameConstants::WINDOW_WIDTH - BRICK_OUT_PADDING*2, GameConstants::WINDOW_HEIGHT * 0.5f);
const int NUM_PER_ROW = 10;
const int ROWS = 5;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	void Init();
	void Update(sf::Time& worldTime);
	void Render(sf::RenderWindow& renderWindow);

private:
	void HandleCollisions();

	Ball mBall;
	Paddle mPaddle;
	std::vector<Brick> mBricks;
};

#endif