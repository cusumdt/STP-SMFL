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

#include "../Utility/buttons.h"

#include "../Enemy/enemy.h"

#include "../Map/levelTutorial.h"

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

	//sf::RectangleShape test; // not used in final game, just for testing purposes.
	sf::RectangleShape rectangles[maxColisionsBoxes];

	////Mouse Trigger
	//sf::Texture mouseTex;
	//sf::Sprite mouseSprite;

	View vw1;
	static	Player* player = new Player();
	static	Enemy* vecEnemy[CANT_ENEMYS];
	static	Camera* camera = new Camera();
	static	Gravity* gravity = new Gravity();
	static	Bullet* bullet[MAXBULLET];
	static LEVELONE* levelone = new LEVELONE();
	static	float _time;
	static	float _collisionTime;

	int testCounter = 0;

	Gameplay::Gameplay() {

	}

	Gameplay::~Gameplay() {

	}

	void Gameplay::init() {


	//	mouseTex.loadFromFile("res/BTN_PLAY.png");
	//	mouseSprite.setTexture(mouseTex);
		srand(time(0));
		levelone->initLevel();
		_time = 0;
		for (int i = 0; i < MAXBULLET; i++) {
			bullet[i] = NULL;
			if (bullet[i] == NULL) {
				bullet[i] = new Bullet();
			}
		}

	
		for (int i = 0; i < CANT_ENEMYS; i++) {
			vecEnemy[i] = NULL;
			if (vecEnemy[i] == NULL) {
				
				randomEnemy = rand() % data + window.getSize().x;
				vecEnemy[i] = new Enemy(1,randomEnemy,rand()% 200 + 400);
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
		//	cout << player->getIsOnGround() << "    " << player->getIsJump() << endl;
		player->movement();
		player->jump();

		//Mouse trigger
		//mouseSprite.setPosition(Vector2f(sf::Mouse::getPosition(window)));

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
		//Enemy

		for (int i = 0; i < CANT_ENEMYS; i++) {
			if (vecEnemy[i] != NULL) {
				if (vecEnemy[i]->getLife() > 0) {
					vecEnemy[i]->movement();
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

		/*if (Collision::PixelPerfectTest(mouseSprite, spriteTest)) {
			cout << "HELLO CRIS!" << endl;
		}*/
		for (int i = 0; i < MAXTILES; i++)
		{
			if (levelone->tiles[i] != NULL && levelone->tiles[i]->getType() == PLATFORM ) {
				if (Collision::PixelPerfectTest(player->getSprite(),levelone->tiles[i]->getSprite())) {
					player->setIsOnGround(true);
				}
			}
		}
	
		for (int i = 0; i < MAXBULLET; i++) {
			if (bullet[i] != NULL) {
				if (bullet[i]->getItsAlive()) {
					for (int j = 0; j < CANT_ENEMYS; j++) {
						if (vecEnemy[j] != NULL && vecEnemy[j]->getLife() > 0) {
							if (Collision::PixelPerfectTest(bullet[i]->getSprite(), vecEnemy[j]->getSprite())) {
								vecEnemy[j]->setLife(0);
								bullet[i]->setItsAlive(false);
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < CANT_ENEMYS; i++) {
			for (int j = 0; j < CANT_ENEMYS; j++) {
				if (Collision::PixelPerfectTest(vecEnemy[i]->getSprite(), vecEnemy[j]->getSprite()) && j != i && vecEnemy[j] != NULL && vecEnemy[i]!=NULL &&vecEnemy[i]->getLife()>0 && vecEnemy[j]->getLife()>0) {
					randomEnemy = rand() % data + window.getSize().x;
					vecEnemy[i]->setX(randomEnemy);
					vecEnemy[i]->setY(rand() % 200 + 400);
				}
			}
		}

	}

	void Gameplay::draw() {
		levelone->drawLevel();
		player->drawPlayer();

		//window.draw(mouseSprite);

		for (int i = 0; i < CANT_ENEMYS; i++) {
			if (vecEnemy[i] != NULL && vecEnemy[i]->getLife()>0) {
				vecEnemy[i]->drawEnemy();
			}
		}
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
		for (int i = 0; i < CANT_ENEMYS; i++) {
			if (vecEnemy[i] != NULL) {
				delete vecEnemy[i];
				vecEnemy[i] = NULL;
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
		if (levelone != NULL) {
			delete levelone;
			levelone = NULL;
		}
	}
}


