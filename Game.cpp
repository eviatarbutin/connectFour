#include "Game.h"
#include "PlayBoard.h"
#include "Player.h"
#include <iostream>

Game* Game::instance = 0;

void Game::newGame()
{
	Player firstPlayer = Player();
	Player secondPlayer = Player();
	PlayBoard::GetInstance()->resetBoard();
	PlayBoard::GetInstance()->PrintMap();
	//game process

	bool finished;
	do {
		finished = firstPlayer.playTurn();
		PlayBoard::GetInstance()->PrintMap();
		if (finished) {
			winnerChar = firstPlayer.playingCharacter;
			break;
		}
		finished = secondPlayer.playTurn();
		PlayBoard::GetInstance()->PrintMap();
		if (finished)
		{
			winnerChar = secondPlayer.playingCharacter;
			break;
		}
	} while (!finished);


	//who won
	bool draw = true;
	for (int i = 0; i < 7; i++) {
		if (PlayBoard::GetInstance()->playBoard[i][5] == ' ') {
			if (winnerChar == firstPlayer.playingCharacter) {
				winner = firstPlayer.name;
				std::cout << "Congratulations " << winner << "! You won the game!\n";
			}
			else if (winnerChar == secondPlayer.playingCharacter) {
				winner = secondPlayer.name;
				std::cout << "Congratulations " << winner << "! You won the game!\n";
			}
			draw = false;
			break;
		}
	}
	if (draw)
	{
	std::cout << "Well played guys, its a draw!\n";
	}


	//game finished with success
	std::cout << "Well dear gamers what would you like to do next?\n";
	char nextStep;
	do
	{
		std::cout << "if you want to play another game enter the letter 'r'\n";
		std::cout << "if you want to quit enter the letter 'q'\n";

		std::cin >> nextStep;
	} while (nextStep!='r'&& nextStep != 'R'&& nextStep != 'q'&& nextStep != 'Q');
	if (nextStep == 'r' || nextStep == 'R')
	{
		Game::GetInstance()->newGame();
	}
	else {
		std::cout << "Thanks for playing in my game!\n";
		std::cout << "The game was made by Eviatar Butin. Goodbye and have a nice day =)";
	}
}

Game::Game()
{}

