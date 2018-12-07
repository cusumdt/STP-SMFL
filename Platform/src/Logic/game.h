#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"
#include "TGUI\TGUI.hpp"

namespace platform {

	extern tmx::TileMap map;
	extern	sf::RenderWindow window;

	
	extern tgui::Gui gui;


	enum ActualScene {
		MenuScene,
		GameScene,
		GameoverScene,
		CreditsScene
	};

	extern ActualScene actualScene;

	class Game {
		static int _currentScene;
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
		static void setCurrentScene(int current);
		static int getCurrentScene();
		ActualScene getActualScene();
	};

}
#endif // !GAME.H
