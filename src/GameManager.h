#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "Ball.h"
#include "Paddle.h"

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
	//std::vector<Brick> mBricks;
};

#endif