#include <SFML/Graphics.hpp>

#include "GameConstants.h"
#include "GameRandom.h"

#if _DEBUG // If Debug Config, use console subsystem
int main()
#else // If Release Config, use windows subsystem
int WinMain()
#endif
{
	// create the main window, prevent it from being resized
	sf::RenderWindow mainWindow(sf::VideoMode(GameConstants::WINDOW_WIDTH, GameConstants::WINDOW_HEIGHT), "Template Project", sf::Style::Titlebar | sf::Style::Close);

	// set framerate
	mainWindow.setFramerateLimit(144);

	// clock for timing
	sf::Clock clock;

	// start the game loop
	while (mainWindow.isOpen())
	{
		// Handle Timing
		sf::Time dt = clock.restart();

		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				mainWindow.close();
		}

		// Update Loop
		{

		}

		// Render Loop
		{
			// Clear window
			mainWindow.clear(sf::Color::Black);

			// Draw stuff here


			// Finish drawing.
			mainWindow.display();
		}
	}

	return 0;
}