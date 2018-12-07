#ifndef BULLET_H
#define BULLET_H
#include "../Logic/game.h"
namespace platform {
	enum Direction {
		RIGHTD, LEFTD
	};
	class Bullet
	{
	private:
		float _x;
		float _y;
		sf::Texture texture;
		sf::Sprite sprite;
		float _time;
		float _timeLive;
		bool _itsAlive;
		Direction _direction;
	public:
		Bullet();
		~Bullet();
		void setX(float x);
		void setY(float y);
		void setItsAlive(bool itsAlive);
		void setDirection(Direction direction);
		void setTime(float time);
		void setTimeLive(float timeLive);
		float getX() { return _x; }
		float getY() { return _y; }
		float getTextureSizeX() { return static_cast<float>(texture.getSize().x); }
		sf::Sprite getSprite() { return sprite; }
		bool getItsAlive() { return _itsAlive; }
		void drawBullet();
		void movement();
	};
}
#endif // !BULLET_H
