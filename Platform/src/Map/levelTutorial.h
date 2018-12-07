#ifndef LEVELTUTOTRIAL_H
#define	LEVELTUTORIAL_H
#include "../Tiles/tiles.h"
#include "../Utility/const_data.h"
#include "../Enemy/enemy.h"
#include "../Player/bullet.h"
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

namespace platform {

	class LevelTutorial {
		int cantEnemys;
	public:
		Enemy* vecEnemy[CANT_ENEMYS];
		Tiles * tiles[MAXTILES];
		LevelTutorial();
		~LevelTutorial();
		int getCantEnemys() { return cantEnemys; }
		void initLevel();
		void updateLevel(Bullet* bullet[], Player* &player);
		void drawLevel();
	};

}

#endif // !LEVELTUTORIAL_H
