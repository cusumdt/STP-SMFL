#ifndef CAMERA_H
#define CAMERA_H
#include "../Logic/game.h"

namespace platform {

	class Camera {
	private:
		sf::Vector2f _pos;
		float _rotation;
	public:
		Camera();
		~Camera();
		float getPosX() { return _pos.x; }
		float getPosY() { return _pos.y; }
		sf::Vector2f getPos() { return _pos; }
		float getRotation() { return _rotation; }
		void setPosX(float posX);
		void setPosY(float posY);
		void setPos(sf::Vector2f pos);
		void setRotation(float rotation);
		void movementCamera(float posX,float posY, float posPlayerInCamera);
		void shakeCamera();
		bool CameraScreenLimiter() { return (_pos.x < map.GetWidth()*map.GetTileWidth() - window.getSize().x); }
	};

}
#endif // !CAMERA_H

