#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameConstants
{
	constexpr int WINDOW_WIDTH = 1920;
	constexpr int WINDOW_HEIGHT = 1080;

	// set the origin of the text to the centre of it
	static void CentreTextOrigin(sf::Text& text)
	{
		text.setOrigin(text.getGlobalBounds().width / 2, 0);
	}

	static sf::Vector2f RoundVector2f(const sf::Vector2f vec2f)
	{
		return sf::Vector2f(std::round(vec2f.x), std::round(vec2f.y));
	}
}

#endif