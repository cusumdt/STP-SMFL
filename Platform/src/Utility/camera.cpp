#include "camera.h"
#include	<iostream>
static const short int velocity = 2;
namespace platform {

	Camera::Camera() {
		_pos.x = 0;
		_pos.y = 0;
		_rotation = 0;
	}

	Camera::~Camera() {
	}

	void Camera::setPosX(float posX) {
		_pos.x = posX;
	}
	void Camera::setPosY(float posY) {
		_pos.y = posY;
	}
	void Camera::setPos(sf::Vector2f pos) {
		_pos = pos;
	}
	void Camera::setRotation(float rotation) {
		_rotation = rotation;
	}
	void Camera::movementCamera(float posX, float posY, float posPlayerInCamera) {
		if (CameraScreenLimiter()) {
			if (posX >= posPlayerInCamera * 2) {
				_pos.x = posX - posPlayerInCamera *2 ;
			}
			_pos.y = posY;
		}

	}
	void Camera::shakeCamera() {
	}
}