#include "gameplay.h"

#include <SFML/Graphics.hpp>
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

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("res/map.tmx"); // Locates the file to be used.

	pugi::xml_node object = doc.child("map").child("objectgroup"); // Clean way to locate a specific group of attributes instead of always typing the same command.

	pugi::xml_node_iterator someObjects = object.begin(); // test purposes, not used for making collision shapes. 
	// It was used to manually select objects ids.

	sf::RectangleShape rectangles[maxColisionsBoxes];

	View vw1;

	static	Player* player = new Player();
	static	Camera* camera = new Camera();
	static	Gravity* gravity = new Gravity();
	static	Bullet* bullet[MAXBULLET];
	static LevelTutorial* levelTutorial = new LevelTutorial();
	static LevelOne* levelOne = new LevelOne();
	static	float _time;
	static	float _collisionTime;

	int testCounter = 0;

	Gameplay::Gameplay() {
		_level = LEVELONE;
	}

	Gameplay::~Gameplay() {

	}

	void Gameplay::setLevel(LevelEnum level) {
		_level = level;
	}
	void Gameplay::init() {
		srand(time(0));
		levelTutorial->initLevel();
		levelOne->initLevel();
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
		////

	}

	void Gameplay::update() {
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

		//PPCD

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
						//Aca condicion de portal
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
						//Aca condicion de portal
					}
				}
			}
			levelOne->updateLevel(bullet, player);
			break;
		default:
			break;
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
		/*for (int i = 0; i < maxButtons; i++) {
			if (buttons[i] != NULL) {
				buttons[i]->setVisible(true);
			}
		}*/
	}

	void Gameplay::hideGUI() {
		/*for (int i = 0; i < maxButtons; i++) {
			if (buttons[i] != NULL) {
				buttons[i]->setVisible(false);
			}
		}*/
	}
}


