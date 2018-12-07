#ifndef CREDITS_H
#define CREDITS_H

#include "../Utility/scenes.h"

namespace platform {
	class Credits : public Scene {
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
