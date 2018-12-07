#include "game.h"

#include "../Player/player.h"
#include "../Utility/camera.h"
#include "../Scenes/gameplay.h"
#include "../Scenes/menu.h"
#include "../Scenes/credits.h"

using namespace tmx;
using namespace sf;

namespace platform {
	//Screen Size
	const short int Game::screenWidth = 1280;
	const short int Game::screenHeight = 768;
	
	ActualScene actualScene = MenuScene;
	int Game:: _currentScene = MenuScene;

	//DeltaTime
	Clock _clock;
	Time _elapsed;
	float Game::_deltaTime = 0;

		//Window renderer
	RenderWindow window(VideoMode(Game::screenWidth, Game::screenHeight), 
	"Simple Platform",
	Style::Close, 
	ContextSettings(24, 8, 4));

	tgui::Gui gui{ window };

	Gameplay gameplay;
	Menu menu;
	Credits credits;
	

	Game::Game() {
		
		_deltaTime = 0;
	}

	Game::~Game() {
		
	}

	void Game::init() {
		_deltaTime = 0;
		menu.init();

	}

	void Game::update() {

		switch (_currentScene) {
		case MenuScene:
			
			menu.update();
			if (menu.getSceneEnd()) {
				menu.deInit();

				switch (_currentScene) {
				case CreditsScene:
					credits.init();
					break;
				case GameScene:
					gameplay.init();
					break;
				case GameoverScene:

					break;
				}
			}
			
			break;
		case GameScene:
			gameplay.update();
			if (gameplay.getSceneEnd()) {
				gameplay.deInit();

				switch (_currentScene) {
				case MenuScene:
					menu.init();
					break;
				case CreditsScene:
					credits.init();
					break;
				case GameoverScene:

					break;
				}
			}
			break;
		case GameoverScene:

			break;
		case CreditsScene:
			credits.update();
				if (credits.getSceneEnd()) {
					credits.deInit();

					switch (_currentScene) {
					case MenuScene:
						menu.init();
						break;
					case GameScene:
						gameplay.init();
						break;
					case GameoverScene:

						break;
					}
				}
			break;
		default:
			break;
		}
	}

	void Game::draw() {
		window.clear();
		window.draw(map);
		switch (_currentScene) {
		case MenuScene:
		    menu.draw();
			break;
		case GameScene:
			gameplay.draw();
			break;
		case GameoverScene:

			break;
		case CreditsScene:
			credits.draw();
			break;
		default:
			break;
		}
			
		gui.draw();

		window.display();
	}

	void Game::deInit() {
			menu.deInit();
			gameplay.deInit();
			credits.deInit();
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
				gui.handleEvent(event);
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

	void Game::setCurrentScene(int current) {
		_currentScene = current;
	}
	int Game::getCurrentScene() {
		return _currentScene;
	}

	ActualScene Game::getActualScene() {
		return actualScene;
	}
}