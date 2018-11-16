#include "game.h"

#include <SFML/Graphics.hpp>
#include "STP/TMXLoader.hpp"

using namespace tmx;
using namespace sf;

namespace G {

	sf::RenderWindow window(sf::VideoMode(1280, 768), "TILED");
	tmx::TileMap map("res/map.tmx");

	Game::Game() {

	}

	Game::~Game() {

	}


	void Game::init() {
		map.ShowObjects(); // Display all the layer objects.
	}

	void Game::update() {

	}

	void Game::draw() {
		// Clear screen
		window.clear();
		// Draw the map
		window.draw(map);
		// Update the window
		window.display();
	}

	void Game::deInit() {
	}

	void Game::runGame() {
		init();

		// Main game loop
		while (window.isOpen())
		{
			// Process events
			sf::Event event;
			while (window.pollEvent(event)) {
				// Close window : exit
				if (event.type == sf::Event::Closed)
					window.close();
			}
			update();
			draw();
		}
		deInit();
	}
}