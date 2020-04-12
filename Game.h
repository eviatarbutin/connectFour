#pragma once
#include <string>
class Game
{
private:
	static Game* instance;
	Game();
public:
	void newGame();
	std::string winner;
	char winnerChar;
	static Game* GetInstance() 
	{

		if (Game::instance == 0) {
			Game::instance = new Game();
		}
		return Game::instance;
	};
};

