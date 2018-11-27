#include "player.h"
#include <iostream>
namespace platform
{

	static const short int velocity = 2;

	Player::Player() {
		_x = initPositionX();
		_y = 500;
		texture.loadFromFile("res/Player/idle/anim1.png");
		sprite.setTexture(texture);
		sprite.setPosition(_x, _y);
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
				_x += velocity;
				sprite.setPosition(_x, _y);
				whatKeyPressed = RIGHT;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (_x > 0) {
				_x -= velocity;
				sprite.setPosition(_x, _y);
				whatKeyPressed = LEFT;
			}
		}else{
			whatKeyPressed = NONE;
		}
	
	}
}