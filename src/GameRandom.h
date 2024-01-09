#ifndef GAME_RANDOM_H
#define GAME_RANDOM_H

#include <random>
#include <ctime>
#include <SFML/System/Vector2.hpp>

namespace GameRandom
{
	inline int Randint(int pMin, int pMax)
	{
		static std::default_random_engine ran((unsigned int)std::time(0));
		return std::uniform_int_distribution<>{pMin, pMax}(ran);
	}

	inline int Randint(int pMax) { return Randint(0, pMax); }

	inline float RandFloat(float pMin, float pMax)
	{
		static std::default_random_engine ran((unsigned int)std::time(0));
		return static_cast<float>(std::uniform_real_distribution<>{pMin, pMax}(ran));
	}

	inline float RandFloat(float pMax) { return RandFloat(0.f, pMax); }

	inline sf::Vector2f RandVector2f(sf::Vector2f pMin, sf::Vector2f pMax)
	{
		float x = RandFloat(pMin.x, pMax.x);
		float y = RandFloat(pMin.y, pMax.y);
		return sf::Vector2f(x, y);
	}

	inline sf::Vector2f RandVector2f(sf::Vector2f pMax)
	{
		float x = RandFloat(pMax.x);
		float y = RandFloat(pMax.y);
		return sf::Vector2f(x, y);
	}

	// r,g,b used to determine the max.
	inline static sf::Color RandomColor(int r, int g, int b)
	{
		return sf::Color(Randint(r), Randint(g), Randint(b));
	}

	inline static sf::Color RandomColor(int minR, int maxR, int minG, int maxG, int minB, int maxB)
	{
		return sf::Color(Randint(minR, maxR), Randint(minG,maxG), Randint(minB, maxB));
	}

	// Random shade between black and white.
	inline static sf::Color RandomColor(int maxVal)
	{
		return sf::Color(Randint(maxVal), Randint(maxVal), Randint(maxVal));
	}

	// random 0 - 255 color on all channels.
	inline static sf::Color RandomColor()
	{
		return sf::Color(Randint(255), Randint(255), Randint(255));
	}
}

#endif