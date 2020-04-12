#pragma once
class PlayBoard
{
private:
	static PlayBoard* instance;
	PlayBoard();
public:
	char playBoard[7][6];
	void resetBoard();
	void PrintMap();
	bool ValidPlace(int numberOfColumn, char playingCharacter);
	bool finished(int numberOfColumn);
	static PlayBoard* GetInstance() {
		if (PlayBoard::instance == 0){
			PlayBoard::instance = new PlayBoard();
		}
		return PlayBoard::instance;
	};
};
