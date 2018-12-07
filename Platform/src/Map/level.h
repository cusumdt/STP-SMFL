#ifndef LEVEL_H
#include "../Player/bullet.h"
namespace platform {
	class Level
	{
	public:
		virtual void initLevel() = 0;
		virtual void updateLevel(Bullet* bullet[], Player* &player) = 0;
		virtual void drawLevel() = 0;
	};
}


#endif // !LEVEL_H
