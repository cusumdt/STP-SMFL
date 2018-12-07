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

	bool Credits::_sceneEnd = false;

	//Buttons
	static const int maxButtons = 1;
	static tgui::Button::Ptr buttons[maxButtons];

	static void actualSceneIsMenu() {
		Credits::setSceneEnd(true);
		Game::setCurrentScene(MenuScene);
	}

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

		buttons[0]->setPosition(160, Game::screenHeight - 100);
		buttons[0]->setText("Back");
		buttons[0]->connect("Pressed", actualSceneIsMenu);

	}
	void Credits::update() {
	}
	void Credits::draw() {

	}
	void Credits::deInit() {
		for (int i = 0; i < maxButtons; i++)
		{
			buttons[i]->setVisible(false);
		}
	}

	bool Credits::getSceneEnd() {
		return _sceneEnd;
	}

	void Credits::setSceneEnd(bool end) {
		_sceneEnd = end;
	}
}


