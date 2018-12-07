#include "levelTutorial.h"
#include "../Utility/Collision.h"
namespace platform {
	
	LevelTutorial::LevelTutorial() {
		for (int i = 0; i < MAXTILES; i++) {
			tiles[i] = NULL;
		}
		for (int i = 0; i < CANT_ENEMYS; i++) {
			vecEnemy[i] = NULL;
		}
		cantEnemys = 0;
	}
	LevelTutorial::~LevelTutorial() {
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
	void LevelTutorial::initLevel() {
		//Scene
		if (tiles[0] == NULL) {
			tiles[0] = new Tiles(
				levelTutorialConstData::PLATFORM1CORDINATE_X,
				levelTutorialConstData::PLATFORM1CORDINATE_Y, 
				PLATFORM, 
				PLATFORM_LARGE
			);
		}
		if (tiles[1] == NULL) {
			tiles[1] = new Tiles(
				levelTutorialConstData::PLATFORM2CORDINATE_X, 
				levelTutorialConstData::PLATFORM2CORDINATE_Y, 
				PLATFORM, 
				PLATFORM_LARGE
			);
		}
		if (tiles[2] == NULL) {
			tiles[2] = new Tiles(
				levelTutorialConstData::PLATFORM3CORDINATE_X, 
				levelTutorialConstData::PLATFORM3CORDINATE_Y, 
				PLATFORM,
				PLATFORM_LARGE
			);
		}
		if (tiles[3] == NULL) {
			tiles[3] = new Tiles(
				levelTutorialConstData::PLATFORM4CORDINATE_X,
				levelTutorialConstData::PLATFORM4CORDINATE_Y, 
				PLATFORM, 
				PLATFORM_LARGE
			);
		}
		if (tiles[4] == NULL) {
			tiles[4] = new Tiles(
				levelTutorialConstData::CACTUS1CORDINATE_X, 
				levelTutorialConstData::CACTUS1CORDINATE_Y,
				DECORATION, 
				CACTUS
			);
		}
		if (tiles[5] == NULL) {
			tiles[5] = new Tiles(
				levelTutorialConstData::GRASS1CORDINATE_X,
				levelTutorialConstData::GRASS1CORDINATE_Y,
				DECORATION, 
				GRASS1
			);
		}
		if (tiles[6] == NULL) {
			tiles[6] = new Tiles(
				levelTutorialConstData::GRASS2CORDINATE_X,
				levelTutorialConstData::GRASS2CORDINATE_Y,
				DECORATION, 
				GRASS2
			);
		}
		if (tiles[7] == NULL) {
			tiles[7] = new Tiles(
				levelTutorialConstData::GRASS3CORDINATE_X,
				levelTutorialConstData::GRASS3CORDINATE_Y,
				DECORATION,
				GRASS1
			);
		}
		if (tiles[8] == NULL) {
			tiles[8] = new Tiles(
				levelTutorialConstData::CACTUS2CORDINATE_X,
				levelTutorialConstData::CACTUS2CORDINATE_Y,
				DECORATION,
				CACTUS
			);
		}
		if (tiles[9] == NULL) {
			tiles[9] = new Tiles(
				levelTutorialConstData::MUSHROOM1CORDINATE_X,
				levelTutorialConstData::MUSHROOM1CORDINATE_Y,
				DECORATION,
				MUSHROOM
			);
		}
		if (tiles[10] == NULL) {
			tiles[10] = new Tiles(
				levelTutorialConstData::PORTALCORDINATE_X,
				levelTutorialConstData::PORTALCORDINATE_Y,
				PORTAL,
				PORTAL1
			);
		}
		if (tiles[11] == NULL) {
			tiles[11] = new Tiles(
				levelTutorialConstData::TEXTKEY1CORDINATE_X,
				levelTutorialConstData::TEXTKEY1CORDINATE_Y,
				DECORATION,
				TUTORIALKEY
			);
		}
		if (tiles[12] == NULL) {
			tiles[12] = new Tiles(
				levelTutorialConstData::TEXTKEY2CORDINATE_X,
				levelTutorialConstData::TEXTKEY2CORDINATE_Y,
				DECORATION,
				TUTORIALKEY2
			);
		}
		if (tiles[13] == NULL) {
			tiles[13] = new Tiles(
				levelTutorialConstData::TEXTCORDINATE_X,
				levelTutorialConstData::TEXTCORDINATE_Y,
				DECORATION,
				TUTORIALTEXT
			);
		}
		if (tiles[14] == NULL) {
			tiles[14] = new Tiles(
				levelTutorialConstData::TEXT2CORDINATE_X,
				levelTutorialConstData::TEXT2CORDINATE_Y,
				DECORATION,
				TUTORIALTEXT2
			);
		}
		//Enemy
		if (vecEnemy[0] == NULL) {
			vecEnemy[0] = new Enemy(
				LIFEENEMY,
				levelTutorialConstData::ENEMY1CORDINATE_X,
				levelTutorialConstData::ENEMY1CORDINATE_Y
			);
			cantEnemys++;
		}
		if (vecEnemy[1] == NULL) {
			vecEnemy[1] = new Enemy(
				LIFEENEMY,
				levelTutorialConstData::ENEMY2CORDINATE_X,
				levelTutorialConstData::ENEMY2CORDINATE_Y
			);
			cantEnemys++;
		}
		if (vecEnemy[2] == NULL) {
			vecEnemy[2] = new Enemy(
				LIFEENEMY,
				levelTutorialConstData::ENEMY3CORDINATE_X,
				levelTutorialConstData::ENEMY3CORDINATE_Y
			);
			cantEnemys++;
		}

	}
	void LevelTutorial::updateLevel(Bullet* bullet[], Player* &player) {

		if (vecEnemy[0] != NULL) {
			if (vecEnemy[0]->getLife() > 0) {
				vecEnemy[0]->movement(
					levelTutorialConstData::ENEMY1MAX_X,
					levelTutorialConstData::ENEMY1MIN_X
				);
			}
		}
		if (vecEnemy[1] != NULL) {
			if (vecEnemy[1]->getLife() > 0) {
				vecEnemy[1]->movement(
					levelTutorialConstData::ENEMY2MAX_X,
					levelTutorialConstData::ENEMY2MIN_X
				);
			}
		}
		if (vecEnemy[2] != NULL) {
			if (vecEnemy[2]->getLife() > 0) {
				vecEnemy[2]->movement(
					levelTutorialConstData::ENEMY3MAX_X,
					levelTutorialConstData::ENEMY3MIN_X
				);
			}
		}
		for (int i = 0; i < MAXBULLET; i++) {
			if (bullet[i] != NULL) {
				if (bullet[i]->getItsAlive()) {
					for (int j = 0; j < CANT_ENEMYS; j++) {
						if (vecEnemy[j] != NULL && vecEnemy[j]->getLife() > 0) {
							if (Collision::PixelPerfectTest(bullet[i]->getSprite(), vecEnemy[j]->getSprite())) {
								vecEnemy[j]->setLife(vecEnemy[j]->getLife()-1);
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
	void LevelTutorial::drawLevel() {
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