#include "bullet.h"
#include <iostream>
namespace platform {
	static const float velocity = 500.0f;
	Bullet::Bullet() {
		_x = 0;
		_y = 200;
		texture.loadFromFile("res/Player/idle/anim1.png");
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
	void Bullet::drawBullet() {
		if (_itsAlive) {
			window.draw(sprite);
		}
	}
	void Bullet::movement() {
		if (_itsAlive) {
			_timeLive += Game::_deltaTime;
			if (_timeLive < 1) {
				_x += velocity * Game::_deltaTime;
				sprite.setPosition(_x, _y);
			}
			else {
				_x = 0;
				_timeLive = 0;
				_itsAlive = false;
			}
		}
	
	}
}