#include "game.h"

#include <iostream>

#include "Player/player.h"
#include "Utility/camera.h"
#include "Scenes/gameplay.h"
#include "Scenes/menu.h"
#include "Scenes/credits.h"
#include "Scenes/gameOver.h"
#include "Scenes/victory.h"



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
	//View Camera
	View vw2;
	//Music
	sf::Music music;

	//Window renderer
	RenderWindow window(VideoMode(Game::screenWidth, Game::screenHeight), 
	"Simple Platform",
	Style::Close, 
	ContextSettings(24, 8, 4));
	
	ActualScene Game::_currentScene = MenuScene;
	Scene* Game::scenes[scenesAmount];

	tgui::Gui gui{ window };

	Game::Game() {
		_deltaTime = 0;
		for (int i = 0; i < scenesAmount; i++) {
			if (scenes[i] != NULL) {
				scenes[i] = NULL;
			}
		}

		scenes[MenuScene] = new Menu();
		scenes[GameScene] = new Gameplay();
		scenes[CreditsScene] = new Credits();
		scenes[GameOverScene] = new GameOver();
		scenes[VictoryScene] = new Victory();
	
	}

	Game::~Game() {
		for (int i = 0; i < scenesAmount; i++){
			if (scenes[i] != NULL) {
				delete scenes[i];
			}
		}
	}

	void Game::init() {
		if (!music.openFromFile("res/Sound/nedkamun.ogg")) {
			std::cout << "error reload sound" << std::endl;
		}
		music.setVolume(100);         // reduce the volume
		music.setLoop(true);         // make it loop
		music.play();
		_deltaTime = 0;

		for (int i = 0; i < scenesAmount; i++){
			if (scenes[i] != NULL){
				scenes[i]->init();
			}
		}
	}

	void Game::update() {

		
	}

	void Game::draw() {
		

		

		
	}

	void Game::deInit() {
		for (int i = 0; i < scenesAmount; i++){
			if (scenes[i] != NULL){
				scenes[i]->deInit();
			}
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

				gui.handleEvent(event);
			}
	

		
			window.clear();
			window.draw(map);

			if (scenes[_currentScene] != NULL){

				scenes[_currentScene]->update();

				scenes[_currentScene]->draw();

				if (_currentScene == GameScene && scenes[_currentScene] != NULL) {
					scenes[GameScene]->draw();
				}

				scenes[_currentScene]->showGUI();
				for (int i = 0; i < scenesAmount; i++){

					if (i != _currentScene){
						scenes[i]->hideGUI();
					}
				}
			}

			gui.draw();
			window.display();
		}
		deInit();
	}

	void Game::setDeltaTime(float elapsed) {
		_deltaTime = elapsed;
	}

	float Game::getDeltaTime() {
		return _deltaTime;
	}

	void Game::setCurrentScene(ActualScene current) {
		_currentScene = current;
	}

	ActualScene Game::getCurrentScene() {
		return _currentScene;
	}

	void Game::refresh() {
        vw2.reset(sf::FloatRect(0.0f, 0.f, Game::screenWidth, Game::screenHeight));
		window.setView(vw2);
		std::cout << "REFRESH" << std::endl;
		scenes[_currentScene]->init();
	}
}