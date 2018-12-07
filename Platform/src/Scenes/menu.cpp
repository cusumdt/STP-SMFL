#include "menu.h"

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

	static Text gameOverText;

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
		logo.loadFromFile("res/logo.png");
		sprite_logo.setTexture(logo);
		sprite_logo.setPosition(static_cast<float>(Game::screenWidth/2), 150.0f);
		sprite_logo.setScale(0.5f, 0.5f);
		sprite_logo.setOrigin(sprite_logo.getTexture()->getSize().x / 2, sprite_logo.getTexture()->getSize().y / 2);

		font.loadFromFile("res/fonts/roboto.ttf");

		gameOverText.setString("V1.1");
		gameOverText.setFont(font);
		gameOverText.setCharacterSize(35);
		gameOverText.setStyle(sf::Text::Regular);
		gameOverText.setFillColor(sf::Color::White);
		gameOverText.setPosition(static_cast<float>(Game::screenWidth - 85), static_cast<float>(Game::screenHeight - 45));

		for (int i = 0; i < maxButtons; i++) {
			buttons[i] = tgui::Button::create();
			gui.add(buttons[i]);
			buttons[i]->setRenderer(blackTheme.getRenderer("Button"));
			buttons[i]->setSize(240, 100);
			buttons[i]->setTextSize(50);
			buttons[i]->setInheritedFont(fontButtons);
		}

		buttons[0]->setPosition(Game::screenWidth / 2 - buttons[0]->getSize().x/2, Game::screenHeight / 2 - 140);
		buttons[0]->setText("Play");
		buttons[0]->connect("Pressed", [&]() {Gameplay::setLevel(LEVELONE); Game::setCurrentScene(GameScene); Game::refresh(); });

		buttons[1]->setPosition(Game::screenWidth / 2 - buttons[0]->getSize().x / 2, Game::screenHeight / 2 - 20);
		buttons[1]->setText("Tutorial");
		buttons[1]->connect("Pressed", [&]() { Gameplay::setLevel(LEVELTUTORIAL); Game::setCurrentScene(GameScene); Game::refresh(); });

		buttons[2]->setPosition(Game::screenWidth / 2 - buttons[0]->getSize().x / 2, Game::screenHeight / 2 + 100);
		buttons[2]->setText("Credits");
		buttons[2]->connect("Pressed", [&]() {Game::setCurrentScene(CreditsScene); Game::refresh(); });

		buttons[3]->setPosition(Game::screenWidth / 2 - buttons[0]->getSize().x / 2, Game::screenHeight / 2 + 220);
		buttons[3]->setText("Exit");
		buttons[3]->connect("Pressed", actualSceneIsExit);
	}
	void Menu::update() {

	}
	void Menu::draw() {
		// Draw it
		window.draw(gameOverText);
		window.draw(sprite_logo);
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


