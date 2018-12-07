#include "gameOver.h"

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
	static const int maxButtons = 3;
	static tgui::Button::Ptr buttons[maxButtons];

	static void actualSceneIsExit() {
		window.close();
	}

	GameOver::GameOver() {

	}
	GameOver::~GameOver() {

	}
	void GameOver::init() {

		font.loadFromFile("res/fonts/roboto.ttf");

		gameOverText.setString("GAME OVER");
		gameOverText.setFont(font);
		gameOverText.setCharacterSize(150);
		gameOverText.setStyle(sf::Text::Bold);
		gameOverText.setFillColor(sf::Color::White);
		gameOverText.setOrigin(static_cast<float>(gameOverText.getCharacterSize() / 2),1.0f);
		gameOverText.setPosition(static_cast<float>(Game::screenWidth/2 - 350), 50.0f);

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
	void GameOver::update() {

	}
	void GameOver::draw() {
		// Draw it
		window.draw(gameOverText);
	}
	void GameOver::deInit() {
	}

	void GameOver::showGUI() {
		for (int i = 0; i < maxButtons; i++) {
			if (buttons[i] != NULL) {
				buttons[i]->setVisible(true);
			}
		}
	}

	void GameOver::hideGUI() {
		for (int i = 0; i < maxButtons; i++) {
			if (buttons[i] != NULL) {
				buttons[i]->setVisible(false);
			}
		}
	}


}


