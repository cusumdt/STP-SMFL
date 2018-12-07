#ifndef CONST_DATA_H
#define CONST_DATA_H
#include <SFML/Graphics.hpp>
#include "STP/TMXLoader.hpp"
namespace platform {
	static const short int  MAXBULLET = 5;
	static const short int POSCORRECTION = 50;
	static const float PLAYER_VELOCITY = 300.0f;
	static const float BULLET_VELOCITY = 700.0F;
	static const short int CANT_ENEMYS = 10;
	static const short int MAXTILES = 200;
	static const short int LIFEENEMY = 3;
	static const char PLATFORM_LARGE[] = "res/Environment/platform_large.png";
	static const char CACTUS[] = "res/Environment/cactus.png";
	static const char GRASS1[] = "res/Environment/grass1.png";
	static const char GRASS2[] = "res/Environment/grass2.png";
	static const char MUSHROOM[] = "res/Environment/mushroom.png";
	static const char PORTAL1[] = "res/Portals/portal.png";
	static const char TUTORIALKEY[] = "res/Tutorial/key.png";
	static const char TUTORIALKEY2[] = "res/Tutorial/space.png";
	static const char TUTORIALTEXT[] = "res/Tutorial/text.png";
	static const char TUTORIALTEXT2[] = "res/Tutorial/text2.png";
	namespace levelTutorialConstData {
		//Platform
		static const int PLATFORM1CORDINATE_X = 600;
		static const int PLATFORM1CORDINATE_Y = 500;
		static const int PLATFORM2CORDINATE_X = 1300;
		static const int PLATFORM2CORDINATE_Y = 300;
		static const int PLATFORM3CORDINATE_X = 1680;
		static const int PLATFORM3CORDINATE_Y = 300;
		static const int PLATFORM4CORDINATE_X = 2300;
		static const int PLATFORM4CORDINATE_Y = 150;
		//-----------------------------------------
		//Cactus
		static const int CACTUS1CORDINATE_X = 2300;
		static const int CACTUS1CORDINATE_Y = -10;
		static const int CACTUS2CORDINATE_X = 1375;
		static const int CACTUS2CORDINATE_Y = 140;
		//-----------------------------------------
		//Grass
		static const int GRASS1CORDINATE_X = 2417;
		static const int GRASS1CORDINATE_Y = 93;
		static const int GRASS2CORDINATE_X = 1680;
		static const int GRASS2CORDINATE_Y = 230;
		static const int GRASS3CORDINATE_X = 2000;
		static const int GRASS3CORDINATE_Y = 243;
		//-----------------------------------------
		//Mushrooms
		static const int MUSHROOM1CORDINATE_X = 600;
		static const int MUSHROOM1CORDINATE_Y = 401;
		//-----------------------------------------
		//Portal
		static const int PORTALCORDINATE_X = 2320;
		static const int PORTALCORDINATE_Y = -10;
		//-----------------------------------------
		//Enemy
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
		//-----------------------------------------
		//Text
		static const int TEXTCORDINATE_X = 100;
		static const int TEXTCORDINATE_Y = 300;
		static const int TEXT2CORDINATE_X = 900;
		static const int TEXT2CORDINATE_Y = 300;
		static const int TEXTKEY1CORDINATE_X = 100;
		static const int TEXTKEY1CORDINATE_Y = 100;
		static const int TEXTKEY2CORDINATE_X = 600;
		static const int TEXTKEY2CORDINATE_Y = 100;
		//-----------------------------------------
	}
	namespace levelOneConstData {
		//Platforms
		static const int PLATFORM1CORDINATE_X = 100;
		static const int PLATFORM1CORDINATE_Y = 150;
		static const int PLATFORM2CORDINATE_X = 500;
		static const int PLATFORM2CORDINATE_Y = 300;
		static const int PLATFORM3CORDINATE_X = 1000;
		static const int PLATFORM3CORDINATE_Y = 100;
		static const int PLATFORM4CORDINATE_X = 1000;
		static const int PLATFORM4CORDINATE_Y = 500;
		static const int PLATFORM5CORDINATE_X = 1500;
		static const int PLATFORM5CORDINATE_Y = 500;
		static const int PLATFORM6CORDINATE_X = 1500;
		static const int PLATFORM6CORDINATE_Y = 150;
		//-----------------------------------------
		//Cactus
		static const int CACTUS1CORDINATE_X = 1000;
		static const int CACTUS1CORDINATE_Y = 340;
		static const int CACTUS2CORDINATE_X = 1700;
		static const int CACTUS2CORDINATE_Y = 340;
		//-----------------------------------------
		//Grass
		static const int GRASS1CORDINATE_X = 110;
		static const int GRASS1CORDINATE_Y = 80;
		static const int GRASS2CORDINATE_X = 1500;
		static const int GRASS2CORDINATE_Y = 80;
		static const int GRASS3CORDINATE_X = 700;
		static const int GRASS3CORDINATE_Y = 243;
		//-----------------------------------------
		//Mushrooms
		static const int MUSHROOM1CORDINATE_X = 600;
		static const int MUSHROOM1CORDINATE_Y = 201;
		//-----------------------------------------
		//Portal
		static const int PORTALCORDINATE_X = 100;
		static const int PORTALCORDINATE_Y = -10;
		//-----------------------------------------
		//Enemy
		static const float ENEMY1CORDINATE_X = 1380;
		static const float ENEMY1CORDINATE_Y = 310;
		static const float ENEMY2CORDINATE_X = 100;
		static const float ENEMY2CORDINATE_Y = 160;
		static const float ENEMY3CORDINATE_X = 500;
		static const float ENEMY3CORDINATE_Y = 100;
		static const float ENEMY4CORDINATE_X = 900;
		static const float ENEMY4CORDINATE_Y = 310;
		static const float ENEMY5CORDINATE_X = 1380;
		static const float ENEMY5CORDINATE_Y = 600;
		static const float ENEMY6CORDINATE_X = 600;
		static const float ENEMY6CORDINATE_Y = 510;
		static const float ENEMY7CORDINATE_X = 2000;
		static const float ENEMY7CORDINATE_Y = 510;
		static const int ENEMY1MAX_X = 1980;
		static const int ENEMY1MIN_X = 1380;
		static const int ENEMY2MAX_X = 460;
		static const int ENEMY2MIN_X = 110;
		static const int ENEMY3MAX_X = 900;
		static const int ENEMY3MIN_X = 680;
		static const int ENEMY4MAX_X = 1250;
		static const int ENEMY4MIN_X = 920;
		static const int ENEMY5MAX_X = 1500;
		static const int ENEMY5MIN_X = 1380;
		static const int ENEMY6MAX_X = 1200;
		static const int ENEMY6MIN_X = 620;
		static const int ENEMY7MAX_X = 2320;
		static const int ENEMY7MIN_X = 2000;
		//-----------------------------------------
	}
}

#endif // !CONST_DATA_H
