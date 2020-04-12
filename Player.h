#pragma once
#include <string>
class Player
{
public:
	std::string name;
	char playingCharacter;
	int numberOfWins;
	bool playTurn();
	Player();
};

