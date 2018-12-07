#ifndef PLAYER_H
#define PLAYER_H
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

#include "Logic/game.h"

#include "bullet.h"

namespace platform {
	enum Key
	{
		RIGHT, LEFT, NONE
	};

	class Player
	{
	private:
		int _life;
		float _x;
		float _y;
		bool _isOnGround;
		bool _isJumping;
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
		void setLife(int life);
		int getLife() { return _life; }
		float getX() { return _x; }
		float getY() { return _y; }
		float getTextureSizeX() { return static_cast<float>(texture.getSize().x); }
		float getTextureSizeY() { return static_cast<float>(texture.getSize().y); }
		float initPositionX() { return (window.getSize().x * 25.0f) / 100; }
		void drawPlayer();
		void movement();
		void jump();
		bool fire();
		sf::RectangleShape getCollider() { return _collider; }
		bool playerScreenLimiter() { return (_x < map.GetWidth()*map.GetTileWidth() - texture.getSize().x); }
		sf::Sprite getSprite() { return sprite; }
		void setIsOnGround(bool isOnGround);
		bool getIsOnGround() { return _isOnGround; }
		bool getIsJump() { return _isJumping; }
		Key getKeyPressed() { return keyPressed; }
		Direction getDirection() { return direction; }
		void init();
	};
}

#endif // !PLAYER_H
