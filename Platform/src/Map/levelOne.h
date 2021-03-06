#ifndef LEVELONE_H
#define LEVELONE_H

#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

#include "Tiles/tiles.h"
#include "Utility/const_data.h"
#include "Enemy/enemy.h"
#include "Player/bullet.h"

namespace platform {

	class LevelOne {
		int cantEnemys;
	public:
		Enemy * vecEnemy[CANT_ENEMYS];
		Tiles * tiles[MAXTILES];
		LevelOne();
		~LevelOne();
		int getCantEnemys() { return cantEnemys; }
		void initLevel();
		void updateLevel(Bullet* bullet[], Player* &player);
		void drawLevel();
	};

}
#endif // !LEVELONE_H
