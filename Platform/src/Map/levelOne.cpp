#include "levelOne.h"
#include "../Utility/Collision.h"
namespace platform {

	LevelOne::LevelOne() {
		for (int i = 0; i < MAXTILES; i++) {
			tiles[i] = NULL;
		}
		for (int i = 0; i < CANT_ENEMYS; i++) {
			vecEnemy[i] = NULL;
		}
		cantEnemys = 0;
	}
	LevelOne::~LevelOne() {
		for (int i = 0; i < MAXTILES; i++) {
			if (tiles[0] != NULL) {
				delete tiles[i];
				tiles[i] = NULL;
			}
		}
		for (int i = 0; i < CANT_ENEMYS; i++) {
			if (vecEnemy[i] != NULL) {
				delete vecEnemy[i];
				vecEnemy[i] = NULL;
			}
		}
	}
	void LevelOne::initLevel() {
		for (int i = 0; i < CANT_ENEMYS; i++) {
			if (vecEnemy[i] != NULL) {
				vecEnemy[i]->setLife(3);
			}
			
		}
		
		cantEnemys = 7;

		//Scene
		if (tiles[0] == NULL) {
			tiles[0] = new Tiles(
				static_cast<float>(levelOneConstData::PLATFORM1CORDINATE_X),
				static_cast<float>(levelOneConstData::PLATFORM1CORDINATE_Y),
				PLATFORM,
				PLATFORM_LARGE
			);
		}
		if (tiles[1] == NULL) {
			tiles[1] = new Tiles(
				static_cast<float>(levelOneConstData::PLATFORM2CORDINATE_X),
				static_cast<float>(levelOneConstData::PLATFORM2CORDINATE_Y),
				PLATFORM,
				PLATFORM_LARGE
			);
		}
		if (tiles[2] == NULL) {
			tiles[2] = new Tiles(
				static_cast<float>(levelOneConstData::PLATFORM3CORDINATE_X),
				static_cast<float>(levelOneConstData::PLATFORM3CORDINATE_Y),
				PLATFORM,
				PLATFORM_LARGE
			);
		}	
		if (tiles[3] == NULL) {
			tiles[3] = new Tiles(
				static_cast<float>(levelOneConstData::PLATFORM4CORDINATE_X),
				static_cast<float>(levelOneConstData::PLATFORM4CORDINATE_Y),
				PLATFORM,
				PLATFORM_LARGE
			);
		}
		if (tiles[4] == NULL) {
			tiles[4] = new Tiles(
				static_cast<float>(levelOneConstData::PLATFORM5CORDINATE_X),
				static_cast<float>(levelOneConstData::PLATFORM5CORDINATE_Y),
				PLATFORM,
				PLATFORM_LARGE
			);
		}
		if (tiles[5] == NULL) {
			tiles[5] = new Tiles(
				static_cast<float>(levelOneConstData::PLATFORM6CORDINATE_X),
				static_cast<float>(levelOneConstData::PLATFORM6CORDINATE_Y),
				PLATFORM,
				PLATFORM_LARGE
			);
		}
		if (tiles[6] == NULL) {
			tiles[6] = new Tiles(
				static_cast<float>(levelOneConstData::PORTALCORDINATE_X),
				static_cast<float>(levelOneConstData::PORTALCORDINATE_Y),
				PORTAL,
				PORTAL1
			);
		}
		if (tiles[7] == NULL) {
			tiles[7] = new Tiles(
				static_cast<float>(levelOneConstData::MUSHROOM1CORDINATE_X),
				static_cast<float>(levelOneConstData::MUSHROOM1CORDINATE_Y),
				DECORATION,
				MUSHROOM
			);
		}
		if (tiles[8] == NULL) {
			tiles[8] = new Tiles(
				static_cast<float>(levelOneConstData::CACTUS1CORDINATE_X),
				static_cast<float>(levelOneConstData::CACTUS1CORDINATE_Y),
				DECORATION,
				CACTUS
			);
		}
		if (tiles[9] == NULL) {
			tiles[9] = new Tiles(
				static_cast<float>(levelOneConstData::CACTUS2CORDINATE_X),
				static_cast<float>(levelOneConstData::CACTUS2CORDINATE_Y),
				DECORATION,
				CACTUS
			);
		}
		if (tiles[10] == NULL) {
			tiles[10] = new Tiles(
				static_cast<float>(levelOneConstData::GRASS1CORDINATE_X),
				static_cast<float>(levelOneConstData::GRASS1CORDINATE_Y),
				DECORATION,
				GRASS2
			);

		}
		if (tiles[11] == NULL) {
			tiles[11] = new Tiles(
				static_cast<float>(levelOneConstData::GRASS2CORDINATE_X),
				static_cast<float>(levelOneConstData::GRASS2CORDINATE_Y),
				DECORATION,
				GRASS2
			);

		}
		if (tiles[12] == NULL) {
			tiles[12] = new Tiles(
				static_cast<float>(levelOneConstData::GRASS3CORDINATE_X),
				static_cast<float>(levelOneConstData::GRASS3CORDINATE_Y),
				DECORATION,
				GRASS1
			);

		}

		//Enemy
		if (vecEnemy[0] == NULL) {
			vecEnemy[0] = new Enemy(
				LIFEENEMY,
				levelOneConstData::ENEMY1CORDINATE_X,
				levelOneConstData::ENEMY1CORDINATE_Y
			);

		}
		if (vecEnemy[1] == NULL) {
			vecEnemy[1] = new Enemy(
				LIFEENEMY,
				levelOneConstData::ENEMY2CORDINATE_X,
				levelOneConstData::ENEMY2CORDINATE_Y
			);

		}
		if (vecEnemy[2] == NULL) {
			vecEnemy[2] = new Enemy(
				LIFEENEMY,
				levelOneConstData::ENEMY3CORDINATE_X,
				levelOneConstData::ENEMY3CORDINATE_Y
			);

		}
		if (vecEnemy[3] == NULL) {
			vecEnemy[3] = new Enemy(
				LIFEENEMY,
				levelOneConstData::ENEMY4CORDINATE_X,
				levelOneConstData::ENEMY4CORDINATE_Y
			);

		}
		if (vecEnemy[4] == NULL) {
			vecEnemy[4] = new Enemy(
				LIFEENEMY,
				levelOneConstData::ENEMY5CORDINATE_X,
				levelOneConstData::ENEMY5CORDINATE_Y
			);
		
		}
		if (vecEnemy[5] == NULL) {
			vecEnemy[5] = new Enemy(
				LIFEENEMY,
				levelOneConstData::ENEMY6CORDINATE_X,
				levelOneConstData::ENEMY6CORDINATE_Y
			);
			
		}
		if (vecEnemy[6] == NULL) {
			vecEnemy[6] = new Enemy(
				LIFEENEMY,
				levelOneConstData::ENEMY7CORDINATE_X,
				levelOneConstData::ENEMY7CORDINATE_Y
			);
		
		}
	}
	void LevelOne::updateLevel(Bullet* bullet[], Player* &player) {

		if (vecEnemy[0] != NULL) {
			if (vecEnemy[0]->getLife() > 0) {
				vecEnemy[0]->movement(
					static_cast<float>(levelOneConstData::ENEMY1MAX_X),
					static_cast<float>(levelOneConstData::ENEMY1MIN_X)
				);
			}
		}
		if (vecEnemy[1] != NULL) {
			if (vecEnemy[1]->getLife() > 0) {
				vecEnemy[1]->movement(
					static_cast<float>(levelOneConstData::ENEMY2MAX_X),
					static_cast<float>(levelOneConstData::ENEMY2MIN_X)
				);
			}
		}
		if (vecEnemy[2] != NULL) {
			if (vecEnemy[2]->getLife() > 0) {
				vecEnemy[2]->movement(
					static_cast<float>(levelOneConstData::ENEMY3MAX_X),
					static_cast<float>(levelOneConstData::ENEMY3MIN_X)
				);
			}
		}
		if (vecEnemy[3] != NULL) {
			if (vecEnemy[3]->getLife() > 0) {
				vecEnemy[3]->movement(
					static_cast<float>(levelOneConstData::ENEMY4MAX_X),
					static_cast<float>(levelOneConstData::ENEMY4MIN_X)
				);
			}
		}
		if (vecEnemy[4] != NULL) {
			if (vecEnemy[4]->getLife() > 0) {
				vecEnemy[4]->movement(
					static_cast<float>(levelOneConstData::ENEMY5MAX_X),
					static_cast<float>(levelOneConstData::ENEMY5MIN_X)
				);
			}
		}
		if (vecEnemy[5] != NULL) {
			if (vecEnemy[5]->getLife() > 0) {
				vecEnemy[5]->movement(
					static_cast<float>(levelOneConstData::ENEMY6MAX_X),
					static_cast<float>(levelOneConstData::ENEMY6MIN_X)
				);
			}
		}
		if (vecEnemy[6] != NULL) {
			if (vecEnemy[6]->getLife() > 0) {
				vecEnemy[6]->movement(
					static_cast<float>(levelOneConstData::ENEMY7MAX_X),
					static_cast<float>(levelOneConstData::ENEMY7MIN_X)
				);
			}
		}
		for (int i = 0; i < MAXBULLET; i++) {
			if (bullet[i] != NULL) {
				if (bullet[i]->getItsAlive()) {
					for (int j = 0; j < CANT_ENEMYS; j++) {
						if (vecEnemy[j] != NULL && vecEnemy[j]->getLife() > 0) {
							if (Collision::PixelPerfectTest(bullet[i]->getSprite(), vecEnemy[j]->getSprite())) {
								vecEnemy[j]->setLife(vecEnemy[j]->getLife() - 1);
								if (vecEnemy[j]->getLife() == 0) {
									cantEnemys--;
								}
								bullet[i]->setTime(0.0f);
								bullet[i]->setTimeLive(0.0f);
								bullet[i]->setItsAlive(false);
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < CANT_ENEMYS; i++) {
			if (vecEnemy[i] != NULL && vecEnemy[i]->getLife() > 0) {
				if (Collision::PixelPerfectTest(player->getSprite(), vecEnemy[i]->getSprite())) {
					player->setLife(0);
				}
			}
		}
	}
	void LevelOne::drawLevel() {
		for (int i = 0; i < MAXTILES; i++)
		{
			if (tiles[i] != NULL) {
				if (tiles[i]->getType() != PORTAL) {
					tiles[i]->drawTile();
				}
				else if (cantEnemys == 0 && tiles[i]->getType() == PORTAL) {
					tiles[i]->drawTile();
				}
			}

		}
		for (int i = 0; i < CANT_ENEMYS; i++) {
			if (vecEnemy[i] != NULL && vecEnemy[i]->getLife()>0) {
				vecEnemy[i]->drawEnemy();
			}
		}
	}
}