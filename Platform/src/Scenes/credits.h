#ifndef CREDITS_H
#define CREDITS_H

#include "../Utility/buttons.h"

namespace platform {
	class Credits {
		static bool _sceneEnd;
	public:
		Credits();
		~Credits();
		void init();
		void update();
		void draw();
		void deInit();
		bool getSceneEnd();
		static void setSceneEnd(bool end);
	};
}
#endif // !CREDITS_H
