#include "gameplay.h"

#include <SFML/Graphics.hpp>
#include "STP/TMXLoader.hpp"

#include "../Logic/game.h"
#include "../Player/player.h"
#include "../Utility/camera.h"

using namespace tmx;
using namespace sf;

namespace platform {

	tmx::TileMap map("res/tile.tmx");

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


