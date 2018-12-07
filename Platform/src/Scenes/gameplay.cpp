#include "gameplay.h"

#include "STP/TMXLoader.hpp"
#include "../pugixml/pugixml.hpp"
#include "../pugixml/pugiconfig.hpp"
#include "../Utility/Collision.h"

#include "../Logic/game.h"
#include "../Player/player.h"
#include "../Utility/camera.h"
#include "../Utility/const_data.h"

#include "../Map/level.h"
#include "../Map/levelTutorial.h"
#include "../Map/levelOne.h"

#include <ctime>

#include <iostream>

using namespace tmx;
using namespace sf;
using namespace std;

namespace platform {
	TileMap map("res/map.tmx");
	static int data = (map.GetWidth()*map.GetTileWidth() - window.getSize().x);
	static int randomEnemy;
	const int maxColisionsBoxes = 1;

	//UI
	static bool _pause = false;
	
	//UI Theme
	static tgui::Theme blackTheme{ "res/themes/Black.txt" };
	//UI Font
	static tgui::Font fontButtons("res/fonts/roboto.ttf");
	static Text pauseText;

	//Buttons
	static const int maxButtons = 3;
	static tgui::Button::Ptr buttons[maxButtons];

	static tgui::Button::Ptr button_pause;


	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("res/map.tmx"); // Locates the file to be used.

	pugi::xml_node object = doc.child("map").child("objectgroup"); // Clean way to locate a specific group of attributes instead of always typing the same command.

	pugi::xml_node_iterator someObjects = object.begin(); // test purposes, not used for making collision shapes. 
	// It was used to manually select objects ids.

	sf::RectangleShape rectangles[maxColisionsBoxes];

	View vw1;

	static	Player* player = new Player();
	static Camera* camera = new Camera();
	static	Gravity* gravity = new Gravity();
	static	Bullet* bullet[MAXBULLET];
	static LevelTutorial* levelTutorial = new LevelTutorial();
	static LevelOne* levelOne = new LevelOne();
	static	float _time;
	static	float _collisionTime;

	int testCounter = 0;

	LevelEnum Gameplay::_level = LEVELONE;

	Gameplay::Gameplay() {
		
	}

	Gameplay::~Gameplay() {

	}

	void Gameplay::setLevel(LevelEnum level) {
		_level = level;
	}

	static void actualSceneIsExit() {
		window.close();
	}

	static void actualSceneIsPaused() {
		_pause = !_pause;
	}

	void Gameplay::init() {
		srand(time(0));
		levelTutorial->initLevel();
		levelOne->initLevel();
		player->init();
		_time = 0;
		for (int i = 0; i < MAXBULLET; i++) {
			bullet[i] = NULL;
			if (bullet[i] == NULL) {
				bullet[i] = new Bullet();
			}
		}

		//// Adding Colission box Rectangles from the .tmx Tilemap File
		//
		int i = 0;
		for (pugi::xml_node_iterator it = object.begin(); it != object.end(); ++it)
		{
			rectangles[i].setPosition(sf::Vector2f(it->attribute("x").as_int(),
				it->attribute("y").as_int()));

			rectangles[i].setSize(sf::Vector2f(it->attribute("width").as_int(),
				it->attribute("height").as_int()));

			rectangles[i].setFillColor(sf::Color::Transparent);
			i++;
		}
		i = 0;
		////////////////////////////////////////////////////////////////////////
		//Pause UI

		font.loadFromFile("res/fonts/roboto.ttf");

		pauseText.setString("PAUSE");
		pauseText.setFont(font);
		pauseText.setCharacterSize(80);
		pauseText.setStyle(sf::Text::Bold);
		pauseText.setFillColor(sf::Color::White);
		pauseText.setOrigin(pauseText.getCharacterSize() / 2, 1);
		pauseText.setPosition(static_cast<float>(Game::screenWidth / 2 - 50), 50.0f);

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
		buttons[0]->connect("Pressed", [&]() {  
			Game::setCurrentScene(GameScene); 
			hideGUI();
			_pause = false;
			button_pause->setVisible(false);
			Game::refresh(); 
			 });

		buttons[1]->setPosition(Game::screenWidth / 2 - buttons[0]->getSize().x / 2, Game::screenHeight / 2 - 20);
		buttons[1]->setText("Menu");
		buttons[1]->connect("Pressed", [&]() { 
			Game::setCurrentScene(MenuScene); 
			hideGUI();
			_pause = false;
			button_pause->setVisible(false);
			Game::refresh(); 

			 });

		buttons[2]->setPosition(Game::screenWidth / 2 - buttons[0]->getSize().x / 2, Game::screenHeight / 2 + 100);
		buttons[2]->setText("Exit");
		buttons[2]->connect("Pressed", [&]() {actualSceneIsExit(); });

		
		button_pause = tgui::Button::create();
		gui.add(button_pause);
		button_pause->setRenderer(blackTheme.getRenderer("Button"));
		button_pause->setSize(50, 50);
		button_pause->setTextSize(25);
		button_pause->setInheritedFont(fontButtons);
		button_pause->setVisible(false);

		button_pause->setPosition(Game::screenWidth - button_pause->getSize().x - 10, button_pause->getSize().y / 2 + 10);
		button_pause->setText("||");
		button_pause->connect("Pressed", [&]() {actualSceneIsPaused(); });
		
		

	}

	void Gameplay::update() {
		if (!_pause) {
			//GameOver
			if (player->getLife() <= 0) {
				camera->init();
				vw1.reset(sf::FloatRect(0.0f, 0.f, Game::screenWidth, Game::screenHeight));
				window.setView(vw1);
				button_pause->setVisible(false);
				Game::setCurrentScene(GameOverScene);
			}

			//Player
			if (!player->getIsOnGround() && !player->getIsJump()) {
				gravity->state(Game::_deltaTime);
				player->setY(player->getY() + gravity->getStrong());
			}

			player->movement();
			player->jump();

			_time += Game::_deltaTime;
			if (player->fire()) {
				if (_time > 0.5f) {
					_time = 0;
					for (int i = 0; i < MAXBULLET; i++) {
						if (bullet[i] != NULL) {
							if (!bullet[i]->getItsAlive()) {
								bullet[i]->setItsAlive(true);
								if (player->getDirection() == RIGHTD) {
									bullet[i]->setX(player->getX() + POSCORRECTION);
								}
								if (player->getDirection() == LEFTD) {
									bullet[i]->setX(player->getX() - POSCORRECTION);
								}
								bullet[i]->setY(player->getY() + (player->getTextureSizeY() / 2));
								bullet[i]->setDirection(player->getDirection());
								i = MAXBULLET;
							}
						}
					}
				}
			}
			//Bullet
			for (int i = 0; i < MAXBULLET; i++) {
				if (bullet[i] != NULL) {
					if (bullet[i]->getItsAlive()) {
						bullet[i]->movement();
					}
				}
			}
			//Camera
			camera->movementCamera(player, FOLLOW);
			vw1.reset(sf::FloatRect(camera->getPosX(), 0.f, Game::screenWidth, Game::screenHeight));
			window.setView(vw1);
			View currentView = window.getView();

			//Collisions
			for (int i = 0; i < maxColisionsBoxes; i++)
			{
				if (player->getCollider().getGlobalBounds().intersects(rectangles[i].getGlobalBounds()))
				{
					player->getCollider().setPosition(player->getCollider().getPosition().x, rectangles[i].getPosition().y - (player->getCollider().getLocalBounds().height));
					player->setIsOnGround(true);
				}
				else
				{
					player->setIsOnGround(false);
				}
			}

			//Level
			switch (_level)
			{
			case platform::LEVELTUTORIAL:
				for (int i = 0; i < MAXTILES; i++)
				{
					if (levelTutorial->tiles[i] != NULL && levelTutorial->tiles[i]->getType() == PLATFORM) {
						if (Collision::PixelPerfectTest(player->getSprite(), levelTutorial->tiles[i]->getSprite())) {
							player->setIsOnGround(true);
						}
					}
					else if (levelTutorial->tiles[i] != NULL && levelTutorial->tiles[i]->getType() == PORTAL) {
						if (Collision::PixelPerfectTest(player->getSprite(), levelTutorial->tiles[i]->getSprite())) {
							camera->init();
							vw1.reset(sf::FloatRect(0.0f, 0.f, Game::screenWidth, Game::screenHeight));
							window.setView(vw1);
							button_pause->setVisible(false);
							Game::setCurrentScene(VictoryScene);
						}
					}
				}
				levelTutorial->updateLevel(bullet, player);
				break;
			case platform::LEVELONE:
				for (int i = 0; i < MAXTILES; i++)
				{
					if (levelOne->tiles[i] != NULL && levelOne->tiles[i]->getType() == PLATFORM) {
						if (Collision::PixelPerfectTest(player->getSprite(), levelOne->tiles[i]->getSprite())) {
							player->setIsOnGround(true);
						}
					}
					else if (levelOne->tiles[i] != NULL && levelOne->tiles[i]->getType() == PORTAL) {
						if (Collision::PixelPerfectTest(player->getSprite(), levelOne->tiles[i]->getSprite())) {
							camera->init();
							vw1.reset(sf::FloatRect(0.0f, 0.f, Game::screenWidth, Game::screenHeight));
							window.setView(vw1);
							button_pause->setVisible(false);
							Game::setCurrentScene(VictoryScene);

						}
					}
				}
				levelOne->updateLevel(bullet, player);
				break;
			default:
				break;
			}
		}
		

	}

	void Gameplay::draw() {
		switch (_level)
		{
		case platform::LEVELTUTORIAL:
			levelTutorial->drawLevel();
			break;
		case platform::LEVELONE:
			levelOne->drawLevel();
			break;
		default:
			break;
		}
		player->drawPlayer();
		for (int i = 0; i < MAXBULLET; i++) {
			if (bullet[i] != NULL) {
				if (bullet[i]->getItsAlive()) {
					bullet[i]->drawBullet();
				}
			}
		}

		//Collisions
		for (int i = 0; i < maxColisionsBoxes; i++)
		{
			window.draw(rectangles[i]); 
				//Collisions
				for (int i = 0; i < maxColisionsBoxes; i++)
				{
					window.draw(rectangles[i]);

				}
		}

	}

	void Gameplay::deInit() {
		for (int i = 0; i < MAXBULLET; i++) {
			if (bullet[i] != NULL) {
				delete bullet[i];
				bullet[i] = NULL;
			}
		}
		if (player != NULL) {
			delete player;
			player = NULL;
		}
		if (camera != NULL) {
			delete camera;
			camera = NULL;
		}
		if (gravity != NULL) {
			delete gravity;
			gravity = NULL;
		}
		if (levelTutorial != NULL) {
			delete levelTutorial;
			levelTutorial = NULL;
		}
	}

	void Gameplay::showGUI() {
		if (_pause) {
			for (int i = 0; i < maxButtons; i++) {
				if (buttons[i] != NULL) {
					buttons[i]->setVisible(true);
				}
			}
			if (button_pause != NULL && Game::getCurrentScene() == GameScene) {
				button_pause->setVisible(true);
			}
		}
		else {
			hideGUI();
			if (button_pause != NULL && Game::getCurrentScene() == GameScene) {
				button_pause->setVisible(true);
			}
			else if (button_pause != NULL) {
				button_pause->setVisible(false);
			}
		}
		
	}

	void Gameplay::hideGUI() {
		for (int i = 0; i < maxButtons; i++) {
			if (buttons[i] != NULL) {
				buttons[i]->setVisible(false);
			}
		}
	}

}


