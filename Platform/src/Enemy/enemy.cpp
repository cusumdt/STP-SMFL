#include "enemy.h"
#include "../Utility/const_data.h"
namespace platform {
	Enemy::Enemy(int life, float x, float y) {
		_life = life;
		_x = x;
		_y = y;
		_isOnGround = false;
		direct = LEFTDE;
		texture.loadFromFile("res/Enemy/enemy.png");
		sprite.setTexture(texture);
		sprite.setPosition(_x, _y);
		sprite.setOrigin(texture.getSize().x / 2, 1);
		_collider.setPosition(sprite.getPosition());
		_collider.setSize(sf::Vector2f(texture.getSize().x, texture.getSize().y));
	}
	Enemy::~Enemy() {
	
	}
	void Enemy::setLife(int life) {
		_life = life;
	}
	void Enemy::setX(float x) {
		_x = x;
	}
	void Enemy::setY(float y) {
		_y = y;
	}
	void Enemy::movement(float maxX, float minX) {
		if (_x>=maxX) {
			direct = LEFTDE;
		}
		else if (_x <= minX) {
			direct = RIGHTDE;
		}
			if (direct == RIGHTDE) {
				_x += PLAYER_VELOCITY * Game::_deltaTime;
				sprite.setPosition(_x, _y);
				sprite.setScale(1, 1);

			}
			else if (direct == LEFTDE) {
				if (_x > 0) {
					_x -= PLAYER_VELOCITY * Game::_deltaTime;
					sprite.setPosition(_x, _y);
					sprite.setScale(-1, 1);
				}
			}
			//Move Collider
			_collider.setPosition(sprite.getPosition());

	}
	void Enemy::drawEnemy(){
		window.draw(sprite);
	}
	void Enemy::setIsOnGround(bool isOnGround) {
		_isOnGround = isOnGround;
	}

}