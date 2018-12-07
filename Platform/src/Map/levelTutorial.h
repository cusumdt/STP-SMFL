#ifndef LEVEL1_H
#define	LEVEL1_H
#include "../Tiles/tiles.h"
#include "../Utility/const_data.h"+
#include "../Enemy/enemy.h"
#include "../Player/bullet.h"
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

namespace platform {

	class LevelTutorial{
		int cantEnemys;
	public:
		Enemy* vecEnemy[CANT_ENEMYS];
		Tiles * tiles[MAXTILES];
		LevelTutorial();
		~LevelTutorial();
		void initLevel();
		void updateLevel(Bullet* bullet[], Player* &player);
		void drawLevel();
	};

}

#endif // !LEVEL1_H
