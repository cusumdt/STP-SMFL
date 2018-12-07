#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "../Utility/scenes.h"
#include "SFML\Graphics.hpp"

namespace platform {

	class GameOver : public Scene {
		// Declare and load a font
		sf::Font font;
	public:
		GameOver();
		~GameOver();
		void init();
		void update();
		void draw();
		void deInit();
		void showGUI();
		void hideGUI();
	};
}
#endif // !GAMEOVER_H


