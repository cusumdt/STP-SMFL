#include "credits.h"

#include <iostream>

#include <SFML/Graphics.hpp>
#include "TGUI\TGUI.hpp"

#include "../Logic/game.h"
#include "../Scenes/gameplay.h"

namespace platform {


	//UI Font
	static tgui::Font fontButtons("res/fonts/roboto.ttf");

	//UI Theme
	static tgui::Theme blackTheme{ "res/themes/Black.txt" };

	//Buttons
	static const int maxButtons = 1;
	static tgui::Button::Ptr buttons[maxButtons];

	Credits::Credits() {

	}
	Credits::~Credits() {

	}
	void Credits::init() {
		
		for (int i = 0; i < maxButtons; i++) {
			buttons[i] = tgui::Button::create();
			gui.add(buttons[i]);
			buttons[i]->setRenderer(blackTheme.getRenderer("Button"));
			buttons[i]->setSize(240, 100);
			buttons[i]->setTextSize(60);
			buttons[i]->setInheritedFont(fontButtons);
		}

		buttons[0]->setPosition(100, Game::screenHeight - 150);
		buttons[0]->setText("Back");
		buttons[0]->connect("Pressed", [&]() { Game::setCurrentScene(MenuScene); });

	}
	void Credits::update() {
	}
	void Credits::draw() {

	}
	void Credits::deInit() {

	}

	void Credits::showGUI() {
		for (int i = 0; i < maxButtons; i++) {
			if (buttons[i] != NULL) {
				buttons[i]->setVisible(true);
			}
		}
	}

	void Credits::hideGUI() {
		for (int i = 0; i < maxButtons; i++) {
			if (buttons[i] != NULL) {
				buttons[i]->setVisible(false);
			}
		}
	}
}


