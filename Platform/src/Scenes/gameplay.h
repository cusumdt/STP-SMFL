#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "../Utility/scenes.h"

namespace platform {
	enum LevelEnum {
		LEVELTUTORIAL,
		LEVELONE
	};
	class Gameplay : public Scene {
		LevelEnum _level;
	public:
		Gameplay();
		~Gameplay();
		void setLevel(LevelEnum level);
		LevelEnum getLevel(){ return _level; }
		void init();
		void update();
		void draw();
		void deInit();
		void showGUI();
		void hideGUI();
	};	
}
#endif // !GAMEPLAY.H
