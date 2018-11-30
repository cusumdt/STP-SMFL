#ifndef MENU_H
#define MENU_H

#include "../Utility/buttons.h"

namespace platform {
	class Menu {
		Texture playTex;
		Texture exitTex;
		Button play;
		Button exit;
	public:
		Menu();
		~Menu();
		void init();
		void update();
		void draw();
	};
}
#endif // !MENU_H

