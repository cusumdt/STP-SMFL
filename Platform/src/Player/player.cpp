#include "player.h"

static const short int velocity = 2;
Player::Player() {
	_x = 100;
	_y = 500;
	texture.loadFromFile("res/Player/idle/anim1.png");
	sprite.setTexture(texture);
	sprite.setPosition(_x + 100, _y);
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
	G::window.draw(sprite);
}

void Player::movement() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (Player::playerScreenLimiter()) {
			_x += velocity;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (_x > 0) {
			_x -= velocity;
		}
	}
	sprite.setPosition(_x, _y);
}