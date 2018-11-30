#include "game.h"

#include "../Player/player.h"
#include "../Utility/camera.h"
#include "../Scenes/gameplay.h"
#include "../Scenes/menu.h"



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
	RenderWindow window(VideoMode(Game::screenWidth, Game::screenHeight), "Simple Platform", Style::None, ContextSettings(24, 8, 4));

	Gameplay gameplay;
	Menu menu;
	ActualScene actualScene = GameScene;

	Game::Game() {
		
		_deltaTime = 0;
	}

	Game::~Game() {
		
	}

	void Game::init() {
		_deltaTime = 0;
		switch (actualScene) {
		case MenuScene:
			menu.init();
			break;
		case GameScene:
			gameplay.init();
			//map.ShowObjects(); // Display all the layer objects.
			//gameplay.update();
			break;
		case GameoverScene:
			//gameOver::update();
			break;
		case CreditsScene:
			//credits::update();
			break;
		default:
			break;
		}

	}

	void Game::update() {
		switch (actualScene) {
		case MenuScene:
			menu.update();
			break;
		case GameScene:
			gameplay.update();
			break;
		case GameoverScene:
			//gameOver::update();
			break;
		case CreditsScene:
			//credits::update();
			break;
		default:
			break;
		}
	}

	void Game::draw() {
		// Clear screen
		window.clear();

		switch (actualScene) {
		case MenuScene:
		    menu.draw();
			break;
		case GameScene:
			// Draw the map
			window.draw(map);
			gameplay.draw();
			break;
		case GameoverScene:
			//gameOver::draw();
			break;
		case CreditsScene:
			//credits::draw();
			break;
		default:
			break;
		}
			
		// Update the window
		window.display();
	}

	void Game::deInit() {
		switch (actualScene) {
		case MenuScene:
			//menu::update();
			break;
		case GameScene:
			gameplay.deInit();
			break;
		case GameoverScene:
			//gameOver::update();
			break;
		case CreditsScene:
			//credits::update();
			break;
		default:
			break;
		}
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
				if (event.type == Event::Closed) {
					window.close();
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
					window.close();
				}
					
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