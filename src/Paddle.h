#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Paddle : public sf::RectangleShape
{
public:
	Paddle();
	Paddle(int x, int y, float width, float height);
	Paddle(sf::Vector2f position, sf::Vector2f size);
	virtual ~Paddle();

	void MovePaddle(sf::Vector2f position);
};

#endif