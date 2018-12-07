#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"
#include "TGUI\TGUI.hpp"

#include "../Utility/scenes.h"

namespace platform {

	extern tmx::TileMap map;
	extern	sf::RenderWindow window;

	
	extern tgui::Gui gui;


	enum ActualScene {
		MenuScene,
		GameScene,
		CreditsScene,
		GameOverScene,
		VictoryScene
	};

	const int scenesAmount = 5;

	class Game {
		static ActualScene _currentScene;
		static Scene* scenes[scenesAmount];
	public:
		static const short int screenWidth;
		static const short int screenHeight;
		static float _deltaTime;
		Game();
		~Game();
		void init();
		void update();
		void draw();
		void deInit();
		void runGame();
		void setDeltaTime(float elapsed);
		float getDeltaTime();

		static void refresh();
		static void setCurrentScene(ActualScene current);
		static ActualScene getCurrentScene();
	};

}
#endif // !GAME.H
