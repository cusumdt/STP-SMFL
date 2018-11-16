#include "game.h"

#include "../Player/player.h"
using namespace tmx;
using namespace sf;

namespace G {
	RenderWindow window (sf::VideoMode(640, 768), "TILED");
	tmx::TileMap map("res/tile.tmx");
	
	sf::View vw1;
	Player* player = new Player();

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
		player->drawPlayer();
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
		
			player->movement();
			vw1.reset(sf::FloatRect(player->getX(),0.f,640,768));
			window.setView(vw1);
			sf::View currentView = window.getView();
		
			update();
			draw();
		}
		deInit();
	}
}