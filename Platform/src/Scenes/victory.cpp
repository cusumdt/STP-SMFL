#include "victory.h"

#include <iostream>

#include "TGUI\TGUI.hpp"

#include "../Logic/game.h"
#include "../Scenes/gameplay.h"

using namespace sf;

namespace platform {


	//UI Font
	static tgui::Font fontButtons("res/fonts/roboto.ttf");

	//UI Theme
	static tgui::Theme blackTheme{ "res/themes/Black.txt" };

	static Text victoryText;

	//Buttons
	static const int maxButtons = 3;
	static tgui::Button::Ptr buttons[maxButtons];

	static void actualSceneIsExit() {
		window.close();
	}

	Victory::Victory() {

	}
	Victory::~Victory() {

	}
	void Victory::init() {

		font.loadFromFile("res/fonts/roboto.ttf");

		victoryText.setString("VICTORY");
		victoryText.setFont(font);
		victoryText.setCharacterSize(150);
		victoryText.setStyle(sf::Text::Bold);
		victoryText.setFillColor(sf::Color::White);
		victoryText.setOrigin(victoryText.getCharacterSize() / 2, 1);
		victoryText.setPosition(static_cast<float>(Game::screenWidth / 2 - 250), 50.0f);

		for (int i = 0; i < maxButtons; i++) {
			buttons[i] = tgui::Button::create();
			gui.add(buttons[i]);
			buttons[i]->setRenderer(blackTheme.getRenderer("Button"));
			buttons[i]->setSize(240, 100);
			buttons[i]->setTextSize(50);
			buttons[i]->setInheritedFont(fontButtons);
		}

		buttons[0]->setPosition(Game::screenWidth / 2 - buttons[0]->getSize().x / 2, Game::screenHeight / 2 - 140);
		buttons[0]->setText("Retry");
		buttons[0]->connect("Pressed", [&]() {  Game::setCurrentScene(GameScene); Game::refresh(); });

		buttons[1]->setPosition(Game::screenWidth / 2 - buttons[0]->getSize().x / 2, Game::screenHeight / 2 - 20);
		buttons[1]->setText("Menu");
		buttons[1]->connect("Pressed", [&]() { Game::setCurrentScene(MenuScene); Game::refresh(); });

		buttons[2]->setPosition(Game::screenWidth / 2 - buttons[0]->getSize().x / 2, Game::screenHeight / 2 + 100);
		buttons[2]->setText("Exit");
		buttons[2]->connect("Pressed", [&]() {actualSceneIsExit(); });
	}
	void Victory::update() {

	}
	void Victory::draw() {
		// Draw it
		window.draw(victoryText);
	}
	void Victory::deInit() {
	}

	void Victory::showGUI() {
		for (int i = 0; i < maxButtons; i++) {
			if (buttons[i] != NULL) {
				buttons[i]->setVisible(true);
			}
		}
	}

	void Victory::hideGUI() {
		for (int i = 0; i < maxButtons; i++) {
			if (buttons[i] != NULL) {
				buttons[i]->setVisible(false);
			}
		}
	}


}


