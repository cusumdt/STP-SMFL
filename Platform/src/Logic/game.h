#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

namespace platform {
	extern tmx::TileMap map;
	extern	sf::RenderWindow window;

	enum ActualScene {
		MenuScene,
		GameScene,
		GameoverScene,
		CreditsScene
	};

	extern ActualScene actualScene;

	class Game {		
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
	};

}
#endif // !GAME.H
