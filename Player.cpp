#include "Player.h"
#include <string>
#include <iostream>
#include "PlayBoard.h"

bool Player::playTurn()
{
	int numberOfColumn;
	do {
		std::cout <<this->name << " please enter the number of column you want to place your character at\n";
		std::cin >> numberOfColumn;
	} while (!(PlayBoard::GetInstance()->ValidPlace(numberOfColumn - 1,this->playingCharacter)));
	return PlayBoard::GetInstance()->finished(numberOfColumn - 1);
}

Player::Player() {
	std::cout << "Hello dear player! Please enter your name or nickname.\n";
	std::cin >> Player::name;
	std::cout << "Nice to meet you " << Player::name << "! Please enter a character which you want to play with (it can be everything even the letter 'z').\n";
	std::cin >> Player::playingCharacter;
	std::cout << "Well thats it. Now you are ready to play, prepare yourself for the game." << std::endl;
	Player::numberOfWins = 0;
}