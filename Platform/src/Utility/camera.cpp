#include "camera.h"
#include	<iostream>
static const short int velocity = 2;
namespace platform {

	Camera::Camera() {
		_pos.x = 0;
		_pos.y = 0;
		_rotation = 0;
		_moveSpeed = 480.0f;
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
	void Camera::setMoveSpeed(float speed) {
		_moveSpeed = speed;
	}
	float Camera::getMoveSpeed() {
		return _moveSpeed;
	}
	void Camera::movementCamera(Player* player, TypeCamera type) {
		if (CameraScreenLimiter()) {
			if (type == FOLLOW) {

				if (player->getKeyPressed() == RIGHT && player->getX() >= _pos.x + window.getSize().x / 2 + 100) {
					_pos.x += _moveSpeed * Game::_deltaTime;
				}
				if (player->getKeyPressed() == LEFT && player->getX() <= _pos.x + window.getSize().x / 2 - 100 && _pos.x > 0) {
					_pos.x -= _moveSpeed * Game::_deltaTime;
				}
				if (player->getKeyPressed() == NONE) {
					if (player->getX() > _pos.x + window.getSize().x / 2) {
						_pos.x += _moveSpeed * Game::_deltaTime;
					}
					if (player->getX() < _pos.x + window.getSize().x / 2 && _pos.x > 0) {
						_pos.x -= _moveSpeed * Game::_deltaTime;
					}
				}
				if (_pos.x < 0) {
					_pos.x = 0;
				}
			}
			if (type == STAGE) {
				if (player->getKeyPressed() == RIGHT && player->getX() >= _pos.x + window.getSize().x) {
					_pos.x += window.getSize().x - player->getTextureSizeX();
				}
				if (player->getKeyPressed() == LEFT && player->getX() <= _pos.x && _pos.x > 0) {
					_pos.x -= window.getSize().x + player->getTextureSizeX();
				}
				if (_pos.x < 0) {
					_pos.x = 0;
				}
			}

			_pos.y = player->getY();
		}
		if (!CameraScreenLimiter()) {
			if (type == FOLLOW && player->getKeyPressed() == LEFT && player->getX() <= _pos.x + window.getSize().x / 2 - 100) {
				_pos.x -= 2;
			}
			if (type == STAGE && player->getKeyPressed() == LEFT && player->getX() <= _pos.x && _pos.x > 0) {
				_pos.x -= window.getSize().x + player->getTextureSizeX();
			}

		}

	}
	void Camera::shakeCamera() {
	}
}