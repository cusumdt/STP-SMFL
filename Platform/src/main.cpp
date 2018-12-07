#include "Logic\game.h"
#include "SFML\Audio.hpp"
#include <iostream>
using namespace platform;

int main(){

	Game* game = new Game();
	game->runGame();
	delete game;
	return 0;
}