#include "gameplay.h"

#include <SFML/Graphics.hpp>
#include "STP/TMXLoader.hpp"
#include "../pugixml/pugixml.hpp"
#include "../pugixml/pugiconfig.hpp"

#include "../Logic/game.h"
#include "../Player/player.h"
#include "../Utility/camera.h"

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
	
	View vw1;
	Player* player = new Player();
	Camera* camera = new Camera();

	int testCounter = 0;

	Gameplay::Gameplay() {

	}
	
	Gameplay::~Gameplay() {

	}
	

	void Gameplay::init() {	
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
		/*test.setPosition(sf::Vector2f(0, 0));
		test.setSize(sf::Vector2f(0, 0));
		test.setFillColor(sf::Color::Transparent);*/
	}

	void Gameplay::update() {
		//Player
		player->movement();

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
				cout << "COLLISION!!!"<< testCounter++<< endl;
				player->setIsOnGround(true);
			}
			else
			{
				player->setIsOnGround(false);
				//map.GetLayer("ground").SetColor({ 255,255,255 });
			}
		}
		
	}

	void Gameplay::draw() {
		player->drawPlayer();

		//Collisions
		for (int i = 0; i < maxColisionsBoxes; i++)
		{
			window.draw(rectangles[i]);
		}
	}
	
	void Gameplay::deInit() {

	}
}


