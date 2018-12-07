#ifndef VICTORY_H
#define VICTORY_H

#include "../Utility/scenes.h"
#include "SFML\Graphics.hpp"

namespace platform {

	class Victory : public Scene {
		// Declare and load a font
		sf::Font font;
	public:
		Victory();
		~Victory();
		void init();
		void update();
		void draw();
		void deInit();
		void showGUI();
		void hideGUI();
	};
}
#endif // !VICTORY_H



