#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"
namespace platform {
	extern tmx::TileMap map;
	extern	sf::RenderWindow window;

	class Game {
	private:

	public:
		Game();
		~Game();
		void init();
		void update();
		void draw();
		void deInit();
		void runGame();
	};

}
#endif // !GAME.H
