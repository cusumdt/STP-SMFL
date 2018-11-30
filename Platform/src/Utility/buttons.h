#ifndef BUTTONS_H
#define BUTTONS_H

#include "SFML\Graphics.hpp"

using namespace sf;

namespace platform {
	class Button {
		Sprite _texture;
	public:
		Button();
		~Button();
		void setTexture(Texture texture);
		Sprite getTexture();
		void setPosition(Vector2f postion);
		Vector2f getPosition();
		bool isButtonHover(Sprite mouse);
		void draw();
	};
}
#endif // !BUTTONS_H
