#ifndef CAMERA_H
#define CAMERA_H
#include "../Logic/game.h"
#include "../Player/player.h"
namespace platform {
	enum TypeCamera
	{
		STAGE,FOLLOW
	};
	class Camera {
	private:
		sf::Vector2f _pos;
		float _rotation;
		float _moveSpeed;
	public:
		Camera();
		~Camera();
		void setPosX(float posX);
		void setPosY(float posY);
		float getPosX() { return _pos.x; }
		float getPosY() { return _pos.y; }
		void setPos(sf::Vector2f pos);
		sf::Vector2f getPos() { return _pos; }
		void setRotation(float rotation);
		float getRotation() { return _rotation; }	
		float getMoveSpeed();
		void setMoveSpeed(float speed);
		void movementCamera(Player* player, TypeCamera type);
		void shakeCamera();
		bool CameraScreenLimiter() { return (_pos.x < map.GetWidth()*map.GetTileWidth() - window.getSize().x); }
	};

}
#endif // !CAMERA_H

