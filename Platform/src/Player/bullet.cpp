#include "bullet.h"
#include "../Utility/const_data.h"
#include <iostream>
namespace platform {
	Bullet::Bullet() {
		_x = 0;
		_y = 200;
		texture.loadFromFile("res/atack.png");
		sprite.setTexture(texture);
		sprite.setPosition(_x, _y);
		_time=0;
		_timeLive = 0;
		_itsAlive = false;
	}
	Bullet::~Bullet() {
	
	}
	void Bullet::setX(float x) {
		_x = x;
	}
	void Bullet::setY(float y) {
		_y = y;
	}
	void Bullet::setItsAlive(bool itsAlive) {
		_itsAlive = itsAlive;
	}
	void Bullet::setDirection(Direction direction) {
		_direction = direction;
	}
	void Bullet::setTime(float time) {
		_time = time;
	}
	void Bullet::setTimeLive(float timeLive) {
		_timeLive = timeLive;
	}
	void Bullet::drawBullet() {
		if (_itsAlive) {
			window.draw(sprite);
		}
	}
	void Bullet::movement() {
		if (_itsAlive) {
			_timeLive += Game::_deltaTime;
			if (_timeLive < 1) {
				if (_direction == RIGHTD) {
					_x += BULLET_VELOCITY * Game::_deltaTime;
					sprite.setPosition(_x, _y);
					sprite.setScale(1, 1);
				}
				if (_direction == LEFTD) {
					_x -= BULLET_VELOCITY * Game::_deltaTime;
					sprite.setPosition(_x, _y);
					sprite.setScale(-1, 1);
				}
			}
			else {
				std::cout << _timeLive << std::endl;
				_x = 0;
				_timeLive = 0;
				_itsAlive = false;
			}
		}
	
	}
}