#include "player.h"

namespace platform
{

	static const float velocity = 500.0f;

	Player::Player() {
		_x = initPositionX();
		_y = 500;
		texture.loadFromFile("res/Player/idle/anim1.png");
		sprite.setTexture(texture);
		sprite.setPosition(_x, _y);
		direction = Direction::RIGHT;
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
				direction = Direction::RIGHT;
				keyPressed = Key::RIGHT;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (_x > 0) {
				_x -= velocity * Game::_deltaTime;
				sprite.setPosition(_x, _y);
				direction = Direction::LEFT;
				keyPressed = Key::LEFT;
			}
		}
		else{
			keyPressed = Key::NONE;
			sprite.setPosition(_x, _y);
		}
	
	}
	bool Player::fire() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			return true;
		}
		return false;
	}
}