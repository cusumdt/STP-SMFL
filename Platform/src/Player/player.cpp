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
		_collider.setSize(sprite.getScale());
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
		else{
			keyPressed = NONE;
		}
		
		//Move Collider
		_collider.setPosition(sprite.getPosition());
		_collider.setSize(sprite.getScale());
	}

	sf::RectangleShape Player::getCollider() {
		return _collider;
	}
}