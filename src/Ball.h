#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics/CircleShape.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball();
	Ball(int x, int y, float radius);
	Ball(sf::Vector2f position, float radius);
	virtual ~Ball();

	void Update();
	void Bounce(bool isLeft);

private:
	sf::Vector2f mVelocity;


	const sf::Vector2f LEFT_LAUNCH{ -1,-1 };
	const sf::Vector2f RIGHT_LAUNCH{ 1,-1 };
};

#endif