#include "buttons.h"
#include "../Utility/Collision.h"
#include <SFML/Graphics.hpp>
#include "../Logic/game.h"

using namespace sf;

namespace platform {

	Button::Button() {
		
	}

	Button::~Button() {

	}

	void Button::setTexture(Texture texture) {
		_texture.setTexture(texture);
	}

	Sprite Button::getTexture() {
		return _texture;
	}

	void Button::setPosition(Vector2f position) {
		_texture.setPosition(position);
	}
	Vector2f Button::getPosition() {
		return _texture.getPosition();
	}

	bool Button::isButtonHover(Sprite mouse) {
		if (Collision::PixelPerfectTest(_texture,mouse)) {
			_texture.setColor(sf::Color(255,255,255,255));
			return true;
		}
		else {
			_texture.setColor(sf::Color(255, 255, 255, 255));
			return false;
		}
	}
	void Button::draw() {
		window.draw(_texture);
	}
}
