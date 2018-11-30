#include "menu.h"

#include <SFML/Graphics.hpp>

#include "../Logic/game.h"
#include "../Scenes/gameplay.h"


namespace platform {

	//Mouse Trigger
	//sf::Texture mouseTex;
	//sf::Sprite mouseSprite;

	sf::Texture buttoon;
	sf::Sprite buttoonSprite;

	Menu::Menu() {
		playTex.loadFromFile("res/BTN_PLAY.png");
		play.setTexture(playTex);
		play.setPosition(Vector2f(150.0f, 150.0f));
	}
	Menu::~Menu() {

	}
	void Menu::init() {
		playTex.loadFromFile("res/BTN_PLAY.png");
		play.setTexture(playTex);
		play.setPosition(Vector2f(150.0f, 150.0f));

		//mouseTex.loadFromFile("res/triggerBox.png");
		//mouseSprite.setTexture(mouseTex);
	}
	void Menu::update() {
		//Mouse trigger
		//mouseSprite.setPosition(Vector2f(sf::Mouse::getPosition(window)));
		//play.isButtonHover(mouseSprite);
		/*if (play.isButtonHover(mouseSprite) && sf::Mouse::isButtonPressed(Mouse::Left)) {
			actualScene = GameScene;
		}*/
	}
	void Menu::draw() {
		window.clear(sf::Color::White);
		//window.draw(mouseSprite);
		window.draw(play.getTexture());
	}
}


