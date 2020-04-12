#include <iostream>
#include "Player.h"
#include "PlayBoard.h"
#include "Game.h"
int main()
{
	Game* game = Game::GetInstance();
	game->newGame();
	return 0;
}