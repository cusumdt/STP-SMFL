#include "player.h"
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
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (_x > initPositionX()) {
				_x -= velocity;
			}
		}
		sprite.setPosition(_x, _y);
	}
}