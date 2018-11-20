#include "Logic\game.h"

using namespace G;

int main(){
	Game* game = new Game();
	game->runGame();
	delete game;
	return 0;
}