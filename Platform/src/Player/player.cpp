#include "player.h"
#include "../Utility/const_data.h"
#include <iostream>
namespace platform
{
	Player::Player() {
		_x = initPositionX();
		_y = 500;
		texture.loadFromFile("res/Player/idle/anim1.png");
		sprite.setTexture(texture);
		sprite.setPosition(_x, _y);
		direction = Direction::RIGHTD;
		_collider.setPosition(sprite.getPosition());
		_collider.setSize(sf::Vector2f(texture.getSize().x, texture.getSize().y));
		_isOnGround = false;
		_isJumping = false;
		_timeJump = 0;
	}

	Player::~Player() {

	}

	void Player::setX(float x) {
		_x = x;
	}

	void Player::setY(float y) {
		_y = y;
	}

	void Player::drawPlayer() {
		window.draw(sprite);
	}

	void Player::movement() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (Player::playerScreenLimiter()) {
				_x += PLAYER_VELOCITY * Game::_deltaTime;
				sprite.setPosition(_x, _y);
				direction = Direction::RIGHTD;
				keyPressed = Key::RIGHT;
				sprite.setScale(1, 1);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					if (_isOnGround) {
						_isJumping = true;
					}
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (_x > 0) {
				_x -= PLAYER_VELOCITY * Game::_deltaTime;
				sprite.setPosition(_x, _y);
				direction = Direction::LEFTD;
				keyPressed = Key::LEFT;
				sprite.setScale(-1, 1);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					if (_isOnGround) {
						_isJumping = true;
					}
				}
			}
		}
		else {
			keyPressed = Key::NONE;
			sprite.setPosition(_x, _y);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				if (_isOnGround) {
					_isJumping = true;
				}
			}
		}

		//Move Collider
		_collider.setPosition(sprite.getPosition());
	}
	void Player::jump() {
		if (_isJumping) {
			_timeJump += Game::_deltaTime;
			std::cout << _timeJump<<std::endl;
			if (_timeJump < 0.2f) {
				_y -= PLAYER_VELOCITY * 2 * Game::_deltaTime;
				sprite.setPosition(_x, _y);
			

			}
			else {
				_isJumping = false;
				_isOnGround = false;
				_timeJump = 0;
			}
		}
	}

	sf::RectangleShape Player::getCollider() {
		return _collider;
	}

	void Player::setIsOnGround(bool isOnGround) {
		_isOnGround = isOnGround;
	}
	bool Player::fire() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			return true;
		}
		return false;
	}
}