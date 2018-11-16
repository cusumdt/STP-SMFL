#ifndef PLAYER_H
#define PLAYER_H
#include "../Logic/game.h"
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
	float getX(){ return _x; }
	float getY(){ return _y; }
	void drawPlayer();
	void movement();
};


#endif // !PLAYER_H
