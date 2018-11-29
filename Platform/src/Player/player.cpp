#include "player.h"

#include <iostream>

namespace platform
{

	static const float velocity = 500.0f;

	Player::Player() {
		_x = initPositionX();
		_y = 500;
		texture.loadFromFile("res/Player/idle/anim1.png");
		sprite.setTexture(texture);
		sprite.setPosition(_x, _y);
		_collider.setPosition(sprite.getPosition());
		_collider.setSize(sf::Vector2f(texture.getSize().x, texture.getSize().y));
		_isOnGround = false;
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
				_x += velocity * Game::_deltaTime;
				sprite.setPosition(_x, _y);
				keyPressed = RIGHT;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (_x > 0) {
				_x -= velocity * Game::_deltaTime;
				sprite.setPosition(_x, _y);
				keyPressed = LEFT;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //TEST then delete this!!! start test
			if (_y > 0 && !_isOnGround) {
				_y += velocity * Game::_deltaTime;
				sprite.setPosition(_x, _y);
				//keyPressed = DOWN;
			}
		} //End test
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //TEST then delete this!!! start test
			if (Player::playerScreenLimiter()) {
				_y -= velocity * Game::_deltaTime;
				sprite.setPosition(_x, _y);
				//keyPressed = UP;
			}
		} //End test
		else{
			keyPressed = NONE;
		}
		
		//Move Collider
		_collider.setPosition(sprite.getPosition());
	}

	sf::RectangleShape Player::getCollider() {
		return _collider;
	}

	void Player::setIsOnGround(bool isOnGround) {
		_isOnGround = isOnGround;
	}
	bool Player::getIsOnGround() {
		return _isOnGround;
	}
}