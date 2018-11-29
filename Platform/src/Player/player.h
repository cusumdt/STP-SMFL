#ifndef PLAYER_H
#define PLAYER_H
#include "../Logic/game.h"
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
		Key keyPressed;
		sf::Texture texture;
		sf::Sprite sprite;

	public:
		Player();
		~Player();
		void setX(float x);
		void setY(float y);
		float getX() { return _x; }
		float getY() { return _y; }
		float getTextureSizeX() { return texture.getSize().x; }
		float initPositionX() { return (window.getSize().x * 50.0f) / 100; }
		void drawPlayer();
		void movement();
		bool playerScreenLimiter() { return (_x < map.GetWidth()*map.GetTileWidth() - texture.getSize().x); }
		Key getKeyPressed() { return keyPressed; }
	};
}

#endif // !PLAYER_H
