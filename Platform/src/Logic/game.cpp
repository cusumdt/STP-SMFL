#include "game.h"

#include "../Player/player.h"
#include "../Utility/camera.h"
using namespace tmx;
using namespace sf;

namespace platform {
	static const short int screenWidth = 1280;
	static const short int screenHeight = 768;

	RenderWindow window (VideoMode(screenWidth, screenHeight), "TILED",Style::Close);

	tmx::TileMap map("res/tile.tmx");
	
	View vw1;
	Player* player = new Player();
	Camera* camera = new Camera();

	Game::Game() {

	}

	Game::~Game() {

	}

	void Game::init() {
		map.ShowObjects(); // Display all the layer objects.
	}

	void Game::update() {
		player->movement();
		camera->movementCamera(player, FOLLOW);

		vw1.reset(sf::FloatRect(camera->getPosX(), 0.f, screenWidth, screenHeight));
		window.setView(vw1);
		View currentView = window.getView();
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
		
			update();
			draw();
		}
		deInit();
	}
}