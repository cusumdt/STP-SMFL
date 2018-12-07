#ifndef MENU_H
#define MENU_H

#include "../Utility/scenes.h"
#include "SFML\Graphics.hpp"

namespace platform {
	
	class Menu : public Scene {
		// Declare and load a font
		sf::Font font;
		sf::Texture logo;
		sf::Sprite sprite_logo;
	public:
		Menu();
		~Menu();
		void init();
		void update();
		void draw();
		void deInit();
		void showGUI();
		void hideGUI();
	};
}
#endif // !MENU_H

