#ifndef PLAYER_H
#define PLAYER_H
#include "../Logic/game.h"
#include "../Utility/gravity.h"
#include "bullet.h"

namespace platform {
	enum Key
	{
		RIGHT, LEFT, NONE
	};

	class Player
	{
	private:
		float _x;
		float _y;
		bool _isOnGround;
		float _timeJump;
		Key keyPressed;
		sf::Texture texture;
		sf::Sprite sprite;
		Direction direction;
		sf::RectangleShape _collider;

	public:
		Player();
		~Player();
		void setX(float x);
		void setY(float y);
		float getX() { return _x; }
		float getY() { return _y; }
		float getTextureSizeX() { return static_cast<float>(texture.getSize().x); }
		float getTextureSizeY() { return static_cast<float>(texture.getSize().y); }
		float initPositionX() { return (window.getSize().x * 50.0f) / 100; }
		void drawPlayer();
		void movement();
		bool fire();
		sf::RectangleShape getCollider();
		bool playerScreenLimiter() { return (_x < map.GetWidth()*map.GetTileWidth() - texture.getSize().x); }
		void setIsOnGround(bool isOnGround);
		bool getIsOnGround() { return _isOnGround; }
		Key getKeyPressed() { return keyPressed; }
		Direction getDirection() { return direction; }
	};
}

#endif // !PLAYER_H
