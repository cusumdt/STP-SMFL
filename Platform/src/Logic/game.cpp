#include "game.h"

#include "../Player/player.h"
#include "../Utility/camera.h"
using namespace tmx;
using namespace sf;

namespace platform {
	//Screen Size
	const short int Game::screenWidth = 1280;
	const short int Game::screenHeight = 768;
	
	//DeltaTime
	Clock _clock;
	Time _elapsed;
	float Game::_deltaTime = 0;

	//Window renderer
	RenderWindow window (VideoMode(Game::screenWidth,Game::screenHeight), "Simple Platform",Style::Close);

	Game::Game() {
		_deltaTime = 0;
	}

	Game::~Game() {

	}

	void Game::init() {
		_deltaTime = 0;
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
			_elapsed = _clock.restart();
			setDeltaTime(_elapsed.asSeconds());

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

	void Game::setDeltaTime(float elapsed) {
		_deltaTime = elapsed;
	}

	float Game::getDeltaTime() {
		return _deltaTime;
	}
}