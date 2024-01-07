#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Paddle : public sf::RectangleShape
{
public:
	Paddle();
	Paddle(int x, int y, float width, float height);
	Paddle(sf::Vector2f position, sf::Vector2f size);
	virtual ~Paddle();

	void Update();
};

#endif