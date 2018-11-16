#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
namespace G {

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
