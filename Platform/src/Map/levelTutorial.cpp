#include "levelTutorial.h"

namespace platform {

	LEVELONE::LEVELONE() {
		for (int i = 0; i < MAXTILES; i++) {
			tiles[i] = NULL;
		}

	}
	LEVELONE::~LEVELONE() {
		for (int i = 0; i < MAXTILES; i++) {
			if (tiles[0] != NULL) {
				delete tiles[i];
				tiles[i] = NULL;
			}
		}
	}
	void LEVELONE::initLevel() {
		if (tiles[0] == NULL) {
			tiles[0] = new Tiles(600, 500, PLATFORM, PLATFORM_LARGE);
		}
		if (tiles[1] == NULL) {
			tiles[1] = new Tiles(1300, 300, PLATFORM, PLATFORM_LARGE);
		}
		if (tiles[2] == NULL) {
			tiles[2] = new Tiles(1680, 300, PLATFORM, PLATFORM_LARGE);
		}
		if (tiles[3] == NULL) {
			tiles[3] = new Tiles(2300, 150, PLATFORM, PLATFORM_LARGE);
		}
		if (tiles[4] == NULL) {
			tiles[4] = new Tiles(2300, -10, DECORATION, CACTUS);
		}
		if (tiles[5] == NULL) {
			tiles[5] = new Tiles(2300 + tiles[4]->getTextureSizeX(), 93, DECORATION, GRASS1);
		}
		if (tiles[6] == NULL) {
			tiles[6] = new Tiles(1680, 230, DECORATION, GRASS2);
		}
		if (tiles[7] == NULL) {
			tiles[7] = new Tiles(1680 + tiles[3]->getTextureSizeX() - tiles[6]->getTextureSizeX(), 243, DECORATION, GRASS1);
		}
		if (tiles[8] == NULL) {
			tiles[8] = new Tiles(1300 + tiles[2]->getTextureSizeX() / 2 - tiles[4]->getTextureSizeX() / 2, 140, DECORATION, CACTUS);
		}
		if (tiles[9] == NULL) {
			tiles[9] = new Tiles(600, 401, DECORATION, MUSHROOM);
		}

	}
	void LEVELONE::drawLevel() {
		for (int i = 0; i < MAXTILES; i++)
		{
			if (tiles[i] != NULL) {
				tiles[i]->drawTile();
			}
		}
	}
}