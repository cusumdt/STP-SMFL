#include "tiles.h"

namespace platform {

	Tiles::Tiles(float x, float y, typeTile type, char texture[]){
		_x = x;
		_y = y;
		_type = type;
		_texture.loadFromFile(texture);
		_sprite.setTexture(_texture);
		_sprite.setPosition(_x, _y);
		_collider.setPosition(_sprite.getPosition());
		_collider.setSize(sf::Vector2f(_texture.getSize().x, _texture.getSize().y));
	}
	void Tiles::setX(float x) {
		_x = x;
	}
	void Tiles::setY(float y) {
		_y = y;
	}
	void Tiles::setType(typeTile type) {
		_type = type;
	}
}