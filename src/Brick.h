#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics/RectangleShape.hpp>

class Brick : public sf::RectangleShape
{
public:
	Brick();
	Brick(int x, int y, float width, float height);
	Brick(int x, int y, float width, float height, sf::Color brickColor);
	Brick(sf::Vector2f position, sf::Vector2f size);
	Brick(sf::Vector2f position, sf::Vector2f size, sf::Color brickColor);
	virtual ~Brick();

	void Update();
};

#endif