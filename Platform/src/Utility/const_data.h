#ifndef CONST_DATA_H
#define CONST_DATA_H
#include <SFML/Graphics.hpp>
#include "STP/TMXLoader.hpp"
namespace platform {
	static const short int  MAXBULLET = 5;
	static const short int POSCORRECTION = 50;
	static const float PLAYER_VELOCITY = 300.0f;
	static const float BULLET_VELOCITY = 700.0F;
	static const short int CANT_ENEMYS = 5;
	static const short int MAXTILES = 200;
	static const short int LIFEENEMY = 3;
	static const char PLATFORM_LARGE[] = "res/Environment/platform_large.png";
	static const char CACTUS[] = "res/Environment/cactus.png";
	static const char GRASS1[] = "res/Environment/grass1.png";
	static const char GRASS2[] = "res/Environment/grass2.png";
	static const char MUSHROOM[] = "res/Environment/mushroom.png";
	static const char PORTAL1[] = "res/Portals/portal.png";
	namespace levelTutorialConstData {
		static const int PLATFORM1CORDINATE_X = 600;
		static const int PLATFORM1CORDINATE_Y = 500;
		static const int PLATFORM2CORDINATE_X = 1300;
		static const int PLATFORM2CORDINATE_Y = 300;
		static const int PLATFORM3CORDINATE_X = 1680;
		static const int PLATFORM3CORDINATE_Y = 300;
		static const int PLATFORM4CORDINATE_X = 2300;
		static const int PLATFORM4CORDINATE_Y = 150;
		static const int CACTUS1CORDINATE_X = 2300;
		static const int CACTUS1CORDINATE_Y = -10;
		static const int GRASS1CORDINATE_X = 2417;
		static const int GRASS1CORDINATE_Y = 93;
		static const int GRASS2CORDINATE_X = 1680;
		static const int GRASS2CORDINATE_Y = 230;
		static const int GRASS3CORDINATE_X = 2000;
		static const int GRASS3CORDINATE_Y = 243;
		static const int CACTUS2CORDINATE_X = 1375;
		static const int CACTUS2CORDINATE_Y = 140;
		static const int MUSHROOM1CORDINATE_X = 600;
		static const int MUSHROOM1CORDINATE_Y = 401;
		static const int PORTALCORDINATE_X = 2320;
		static const int PORTALCORDINATE_Y = -10;
		static const float ENEMY1CORDINATE_X = 1380;
		static const float ENEMY1CORDINATE_Y = 310;
		static const float ENEMY2CORDINATE_X = 1380;
		static const float ENEMY2CORDINATE_Y= 600;
		static const float ENEMY3CORDINATE_X = 600;
		static const float ENEMY3CORDINATE_Y = 510;
		static const int ENEMY1MAX_X = 1980;
		static const int ENEMY1MIN_X = 1380;
		static const int ENEMY2MAX_X = 1980;
		static const int ENEMY2MIN_X = 1600;
		static const int ENEMY3MAX_X = 900;
		static const int ENEMY3MIN_X = 680;
	}
}

#endif // !CONST_DATA_H
