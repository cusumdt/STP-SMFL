#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "../Utility/scenes.h"

namespace platform {

	class Gameplay : public Scene {
	public:
		Gameplay();
		~Gameplay();
		void init();
		void update();
		void draw();
		void deInit();
		void showGUI();
		void hideGUI();
	};	
}
#endif // !GAMEPLAY.H
