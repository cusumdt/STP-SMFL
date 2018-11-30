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

#include <iostream>

using namespace tmx;
using namespace sf;
using namespace std;

namespace platform {
	TileMap map("res/map.tmx");

	const int maxColisionsBoxes = 1;

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("res/map.tmx"); // Locates the file to be used.

	pugi::xml_node object = doc.child("map").child("objectgroup"); // Clean way to locate a specific group of attributes instead of always typing the same command.

	pugi::xml_node_iterator someObjects = object.begin(); // test purposes, not used for making collision shapes. 
	// It was used to manually select objects ids.

	//sf::RectangleShape test; // not used in final game, just for testing purposes.
	sf::RectangleShape rectangles[maxColisionsBoxes];

	//Pixel Perfect Collision Detection Example
	sf::Texture texture;
	sf::Sprite spriteTest;

	View vw1;
	Player* player = new Player();
	Camera* camera = new Camera();

	Gravity* gravity = new Gravity();
	Bullet* bullet[MAXBULLET];
	float _time;


	int testCounter = 0;

	Gameplay::Gameplay() {

	}

	Gameplay::~Gameplay() {

	}

	void Gameplay::init() {

		_time = 0;
		for (int i = 0; i < MAXBULLET; i++) {
			bullet[i] = NULL;
			if (bullet[i] == NULL) {
				bullet[i] = new Bullet();
			}
		}

		//Pixel Perfect init
		texture.loadFromFile("res/test.png");
		spriteTest.setTexture(texture);
		spriteTest.setPosition(20, 50);

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
		//	cout << player->getIsOnGround() << "    " << player->getIsJump() << endl;
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
				//map.GetLayer("ground").SetColor({ 255,0,0 });
				cout << "COLLISION!!!" << testCounter++ << endl;
				player->setIsOnGround(true);
			}
			else
			{
				player->setIsOnGround(false);
				//map.GetLayer("ground").SetColor({ 255,255,255 });
			}
		}

		//PPCD
		if (Collision::PixelPerfectTest(player->getSprite(), spriteTest)) {
			cout << "HELLO CRIS!" << endl;
		}

	}

	void Gameplay::draw() {
		player->drawPlayer();
		window.draw(spriteTest);
		//Collisions
		for (int i = 0; i < maxColisionsBoxes; i++)
		{
			window.draw(rectangles[i]); 

			for (int i = 0; i < MAXBULLET; i++) {
				if (bullet[i] != NULL) {
					if (bullet[i]->getItsAlive()) {
						bullet[i]->drawBullet();
					}
				}


				//Collisions
				for (int i = 0; i < maxColisionsBoxes; i++)
				{
					window.draw(rectangles[i]);

				}
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
	}
}


