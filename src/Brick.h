#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics/RectangleShape.hpp>

class Brick : public sf::RectangleShape
{
public:
	Brick();
	Brick(int x, int y, float width, float height);
	Brick(sf::Vector2f position, sf::Vector2f size);
	virtual ~Brick();

	void Update();
};

#endif