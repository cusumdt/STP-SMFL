#ifndef CREDITS_H
#define CREDITS_H

#include "../Utility/scenes.h"
#include "SFML/Graphics.hpp"

namespace platform {
	class Credits : public Scene {
		sf::Texture bg;
		sf::Sprite credits_bg;
	public:
		Credits();
		~Credits();
		void init();
		void update();
		void draw();
		void deInit();
		void showGUI();
		void hideGUI();
	};
}
#endif // !CREDITS_H
