#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace platform {
	enum LevelEnum {
		LEVELTUTORIAL,
		LEVELONE
	};
	class Gameplay {
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
	};	
}
#endif // !GAMEPLAY.H
