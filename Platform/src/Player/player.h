#ifndef PLAYER_H
#define PLAYER_H
#include "../Logic/game.h"
namespace platform {
	enum KeyPressed
	{
		RIGHT, LEFT, NONE
	};
	class Player
	{
	private:
		float _x;
		float _y;
		KeyPressed whatKeyPressed;
		sf::Texture texture;
		sf::Sprite sprite;

	public:
		Player();
		~Player();
		void setX(float x);
		void setY(float y);
		float getX() { return _x; }
		float getY() { return _y; }
		KeyPressed getWhatKeyPressed(){ return whatKeyPressed; }
		float getTextureSizeX() { return texture.getSize().x; }
		void drawPlayer();
		void movement();
		bool playerScreenLimiter() { return (_x < map.GetWidth()*map.GetTileWidth() - texture.getSize().x); }
		float initPositionX() { return (window.getSize().x * 50.0f) / 100; }
	};

}

#endif // !PLAYER_H
