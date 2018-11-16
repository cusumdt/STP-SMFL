#ifndef CAMERA_H
#define CAMERA_H
#include "../Logic/game.h"
class Camera
{
private:
	sf::Vector2f _pos
	float _rotation;
public:
	Camera();
	~Camera();
	float getPosX() { return _pos.x; }
	float getPosY() { return _pos.y; }
	float getPos() {return _pos}
	float getRotation() { return _rotation; }
	void setPos(float posX);
	void setPos(float posY);
	void setPos(sf::Vector2f pos);
	void setRotation(float rotation);
	void movementCamera();
	void shakeCamera();
};

#endif // !CAMERA_H

