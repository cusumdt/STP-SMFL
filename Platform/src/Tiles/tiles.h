#ifndef TILES_H
#define TILES_H
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"
namespace platform {
	
	enum typeTile {
		PLATFORM,
		WALL,
		DECORATION
	};
	class Tiles{
	private:
		float _x;
		float _y;
		typeTile _type;
		sf::Texture _texture;
		sf::Sprite _sprite;
		sf::RectangleShape _collider;
	public:
		Tiles(float x, float y, typeTile type, sf::Sprite sprite);
		Tiles(float x, float y, typeTile type, sf::Texture texture);
		Tiles(float x, float y, typeTile type,const char texture[]);
		void setX(float x);
		void setY(float y);
		void setType(typeTile type);
		float getX() { return _x; }
		float getY() { return _y; }
		typeTile getType() { return _type; }
		float getTextureSizeX() { return static_cast<float>(_texture.getSize().x); }
		float getTextureSizeY() { return static_cast<float>(_texture.getSize().y); }
		sf::RectangleShape getCollider() { return _collider; }
		sf::Sprite getSprite() { return _sprite; }
		void drawTile();
	};
}

#endif // !TILES_H
