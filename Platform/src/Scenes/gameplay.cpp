#include "gameplay.h"

#include <SFML/Graphics.hpp>
#include "STP/TMXLoader.hpp"

#include "../Logic/game.h"
#include "../Player/player.h"
#include "../Utility/camera.h"
#include "../Utility/const_data.h"
using namespace tmx;
using namespace sf;

namespace platform {
	tmx::TileMap map("res/tile.tmx");

	View vw1;
	Player* player = new Player();
	Camera* camera = new Camera();
	Gravity* gravity = new Gravity();
	Bullet* bullet[MAXBULLET];
	float _time;
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
	}

	void Gameplay::update() {
		//Player
		//gravity->state(Game::_deltaTime);
		//player->setY( player->getY()+ gravity->getStrong());
		player->movement();
		_time += Game::_deltaTime;
		if (player->fire()) {
			if (_time > 0.5f) {
				_time = 0;
				for (int i = 0; i < MAXBULLET; i++) {
					if (bullet[i] != NULL) {
						if (!bullet[i]->getItsAlive()) {
							bullet[i]->setItsAlive(true);
							if (player->getDirection() == RIGHTD) {
								bullet[i]->setX(player->getX() + 2);
							}
							if (player->getDirection() == LEFTD) {
								bullet[i]->setX(player->getX() - 2);
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
	}

	void Gameplay::draw() {
		player->drawPlayer();
		for (int i = 0; i < MAXBULLET; i++) {
			if (bullet[i] != NULL) {
				if (bullet[i]->getItsAlive()) {
					bullet[i]->drawBullet();
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


