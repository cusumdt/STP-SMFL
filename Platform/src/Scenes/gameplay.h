#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace platform {

	class Gameplay {
		static bool _sceneEnd;
	public:
		Gameplay();
		~Gameplay();
		void init();
		void update();
		void draw();
		void deInit();
		bool getSceneEnd();
		static void setSceneEnd(bool end);
	};	
}
#endif // !GAMEPLAY.H
