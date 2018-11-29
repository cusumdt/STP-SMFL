#include "gameplay.h"

#include <SFML/Graphics.hpp>
#include "STP/TMXLoader.hpp"
#include "../pugixml/pugixml.hpp"
#include "../pugixml/pugiconfig.hpp"

#include "../Logic/game.h"
#include "../Player/player.h"
#include "../Utility/camera.h"

using namespace tmx;
using namespace sf;

namespace platform {

	TileMap map("res/map.tmx");
	
	const int maxColisionsBoxes = 1;

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("res/map.tmx"); // Locates the file to be used.

	pugi::xml_node object = doc.child("map").child("objectgroup"); // Clean way to locate a specific group of attributes instead of always typing the same command.

	pugi::xml_node_iterator someObjects = object.begin(); // test purposes, not used for making collision shapes. 
	// It was used to manually select objects ids.

	
	View vw1;
	Player* player = new Player();
	Camera* camera = new Camera();

	Gameplay::Gameplay() {

	}
	
	Gameplay::~Gameplay() {

	}
	

	void Gameplay::init() {	
		
	}

	void Gameplay::update() {
		//Player
		player->movement();

		//Camera
		camera->movementCamera(player, FOLLOW);
		vw1.reset(sf::FloatRect(camera->getPosX(), 0.f, Game::screenWidth, Game::screenHeight));
		window.setView(vw1);
		View currentView = window.getView();
	}

	void Gameplay::draw() {
		player->drawPlayer();
	}
	
	void Gameplay::deInit() {

	}
}


