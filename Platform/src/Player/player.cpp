#include "player.h"

#include <iostream>

#include "Utility/const_data.h"

namespace platform
{
	Player::Player() {
		texture.loadFromFile("res/pj.png");
		init();
	}

	Player::~Player() {

	}

	void Player::init() {
		_x = initPositionX();
		_y = 500;
		sprite.setTexture(texture);
		sprite.setPosition(_x, _y);
		sprite.setOrigin(static_cast<float>(texture.getSize().x / 2), 1.0f);
		direction = Direction::RIGHTD;
		_collider.setPosition(sprite.getPosition());
		_collider.setSize(sf::Vector2f(static_cast<float>(texture.getSize().x), static_cast<float>(texture.getSize().y)));
		_isOnGround = false;
		_isJumping = false;
		_timeJump = 0;
		_life = 1;
	}

	void Player::setLife(int life) {
		_life = life;
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
		if (_life > 0) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (Player::playerScreenLimiter()) {
					_x += PLAYER_VELOCITY * Game::_deltaTime;
					sprite.setPosition(_x, _y);
					direction = Direction::RIGHTD;
					keyPressed = Key::RIGHT;
					sprite.setScale(1, 1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					if (_isOnGround) {
						_isJumping = true;
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (_x > texture.getSize().x / 2) {
					_x -= PLAYER_VELOCITY * Game::_deltaTime;
					sprite.setPosition(_x, _y);
					direction = Direction::LEFTD;
					keyPressed = Key::LEFT;
					sprite.setScale(-1, 1);

				}
				else {
					_x = static_cast<float>(texture.getSize().x / 2);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					if (_isOnGround) {
						_isJumping = true;
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
	}
	void Player::jump() {
		if (_life > 0) {
			if (_isJumping) {
				_timeJump += Game::_deltaTime;
				if (_timeJump < 0.5f) {
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