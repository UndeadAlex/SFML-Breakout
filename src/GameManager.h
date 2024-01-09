#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

#include "GameConstants.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

const int BRICK_OUT_PADDING = 50; // in px
const int BRICK_IN_PADDING = 4; // in px
const sf::IntRect BRICK_AREA (BRICK_OUT_PADDING, BRICK_OUT_PADDING, GameConstants::WINDOW_WIDTH - BRICK_OUT_PADDING*2, GameConstants::WINDOW_HEIGHT * 0.5f);
const int NUM_PER_ROW = 14;
const int ROWS = 8;

class GameManager
{
public:
	GameManager(sf::RenderWindow& window);
	virtual ~GameManager();

	void Init();
	void Update(sf::Time& worldTime);
	void Render();

private:
	void HandleCollisions();

	void UpdateScoreText();

	int score = 0;

	Ball mBall;
	Paddle mPaddle;
	std::vector<Brick> mBricks;

	// UI
	sf::Font stdFont;
	sf::Text scoreText;

	sf::RenderWindow& mRenderWindow;
};

#endif