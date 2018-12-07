#ifndef MENU_H
#define MENU_H

#include "../Utility/scenes.h"

namespace platform {
	
	class Menu : public Scene {
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

