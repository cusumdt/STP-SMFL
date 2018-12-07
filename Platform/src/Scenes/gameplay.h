#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "../Utility/scenes.h"
#include "SFML\Graphics.hpp"

namespace platform {
	enum LevelEnum {
		LEVELTUTORIAL,
		LEVELONE
	};

	class Gameplay : public Scene {
		static LevelEnum _level;
		
		// Declare and load a font
		sf::Font font;
	public:
		Gameplay();
		~Gameplay();
		static void setLevel(LevelEnum level);
		static LevelEnum getLevel(){ return _level; }
		void init();
		void update();
		void draw();
		void deInit();
		void showGUI();
		void hideGUI();
	};	
}
#endif // !GAMEPLAY.H
