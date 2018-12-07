#include "menu.h"

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
	static const int maxButtons = 4;
	static tgui::Button::Ptr buttons[maxButtons];

	static void actualSceneIsWorking() {
		std::cout << "This Button Work" << std::endl;
	}

	static void actualSceneIsExit() {
		window.close();
	}

	Menu::Menu() {

	}
	Menu::~Menu() {

	}
	void Menu::init() {
		
		for (int i = 0; i < maxButtons; i++) {
			buttons[i] = tgui::Button::create();
			gui.add(buttons[i]);
			buttons[i]->setRenderer(blackTheme.getRenderer("Button"));
			buttons[i]->setSize(240, 100);
			buttons[i]->setTextSize(60);
			buttons[i]->setInheritedFont(fontButtons);
		}

		buttons[0]->setPosition(Game::screenWidth / 2 - 120, Game::screenHeight / 2 - 140);
		buttons[0]->setText("Play");
		buttons[0]->connect("Pressed", [&]() {Game::setCurrentScene(GameScene); });

		buttons[1]->setPosition(Game::screenWidth / 2 - 120, Game::screenHeight / 2 - 20);
		buttons[1]->setText("Tutorial");
		buttons[1]->connect("Pressed", actualSceneIsWorking);

		buttons[2]->setPosition(Game::screenWidth / 2 - 120, Game::screenHeight / 2 + 100);
		buttons[2]->setText("Credits");
		buttons[2]->connect("Pressed", [&]() {Game::setCurrentScene(CreditsScene); });

		buttons[3]->setPosition(Game::screenWidth / 2 - 120, Game::screenHeight / 2 + 220);
		buttons[3]->setText("Exit");
		buttons[3]->connect("Pressed", actualSceneIsExit);
	}
	void Menu::update() {

	}
	void Menu::draw() {
		
	}
	void Menu::deInit() {
	}

	void Menu::showGUI(){
		for (int i = 0; i < maxButtons; i++){
			if (buttons[i] != NULL){
				buttons[i]->setVisible(true);
			}
		}
	}

	void Menu::hideGUI(){
		for (int i = 0; i < maxButtons; i++){
			if (buttons[i] != NULL){
				buttons[i]->setVisible(false);
			}
		}
	}

	
}


