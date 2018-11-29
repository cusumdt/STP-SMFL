#ifndef BULLET_H
#define BULLET_H
#include "../Logic/game.h"
namespace platform {

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
	public:
		Bullet();
		~Bullet();
		void setX(float x);
		void setY(float y);
		void setItsAlive(bool itsAlive);
		float getX() { return _x; }
		float getY() { return _y; }
		float getTextureSizeX() { return static_cast<float>(texture.getSize().x); }
		bool getItsAlive() { return _itsAlive; }
		//float initPositionX() { return (window.getSize().x * 50.0f) / 100; }
		void drawBullet();
		void movement();
	};
}
#endif // !BULLET_H
