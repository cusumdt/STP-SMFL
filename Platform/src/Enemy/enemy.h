#ifndef ENEMY_H
#define ENEMY_H
#include "../Logic/game.h"
#include "../Utility/gravity.h"
namespace platform {
	enum DirectEnemy {
		RIGHTDE, LEFTDE
	};
	class Enemy {

	private:
		int _life;
		float _x;
		float _y;
		bool _isOnGround;
		DirectEnemy direct;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::RectangleShape _collider;
	public:
		Enemy(int life, float x, float y);
		~Enemy();
		void setLife(int life);
		void setX(float x);
		void setY(float y);
		float getX() { return _x; }
		float getY() { return _y; }
		float getTextureSizeX() { return static_cast<float>(texture.getSize().x); }
		float getTextureSizeY() { return static_cast<float>(texture.getSize().y); }
		int getLife() { return _life; }
		sf::Sprite getSprite() { return sprite; }
		void movement(float maxX, float minX);
		void drawEnemy();
		sf::RectangleShape getCollider() { return _collider; };
		void setIsOnGround(bool isOnGround);
		bool getIsOnGround() { return _isOnGround; }
	};
}
#endif //!ENEMY_H