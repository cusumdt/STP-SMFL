#ifndef PLAYER_H
#define PLAYER_H
#include "../Logic/game.h"
namespace platform {

	class Player
	{
	private:
		float _x;
		float _y;
		sf::Texture texture;
		sf::Sprite sprite;

	public:
		Player();
		~Player();
		void setX(float x);
		void setY(float y);
		float getX() { return _x; }
		float getY() { return _y; }
		void drawPlayer();
		void movement();
		bool playerScreenLimiter() { return (_x < map.GetWidth()*map.GetTileWidth() - texture.getSize().x); }
		float initPositionX() { return (window.getSize().x * 25.0f) / 100; }
	};

}

#endif // !PLAYER_H
