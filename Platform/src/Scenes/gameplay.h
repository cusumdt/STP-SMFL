#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace platform {

	class Gameplay {
	public:
		Gameplay();
		~Gameplay();
		void init();
		void update();
		void draw();
		void deInit();
	};	
}
#endif // !GAMEPLAY.H
