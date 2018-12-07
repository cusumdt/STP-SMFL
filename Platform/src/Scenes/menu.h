#ifndef MENU_H
#define MENU_H

#include "../Utility/buttons.h"

namespace platform {
	
	class Menu {
		static bool _sceneEnd;
	public:
		Menu();
		~Menu();
		void init();
		void update();
		void draw();
		void deInit();
		bool getSceneEnd();
		static void setSceneEnd(bool end);
	};
}
#endif // !MENU_H

