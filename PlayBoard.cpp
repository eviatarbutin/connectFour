#include "PlayBoard.h"
#include <iostream>

PlayBoard* PlayBoard::instance = 0;

bool PlayBoard::finished(int numberOfColumn)
{
	int numberOfRow;
	// find the place of the putted chracter
	for (int i = 5; i >=0; i--)
	{
		if (PlayBoard::GetInstance()->playBoard[numberOfColumn][i] != ' ')
		{
			numberOfRow = i;
			break;
		}
	}
	char playingChar = PlayBoard::GetInstance()->playBoard[numberOfColumn][numberOfRow];

	// up and down
	bool goForward = true;
	bool goBackwards = true;
	int combo = 0;
	for (int i = 1; i < 4 && combo < 4; i++) {
		if (numberOfRow + i > 5)
		{
			goForward = false;
		}
		if (numberOfRow - i < 0)
		{
			goBackwards = false;
		}
		if (goForward && PlayBoard::GetInstance()->playBoard[numberOfColumn][numberOfRow + i] == playingChar) {
			combo++;
		}
		else {
			goForward = false;
		}
		if (goBackwards && PlayBoard::GetInstance()->playBoard[numberOfColumn][numberOfRow - i] == playingChar) {
			combo++;
		}
		else {
			goBackwards = false;
		}
		if (!goBackwards && !goForward)
		{
			break;
		}
	}
	if (combo >= 3)
		return true;
	
	
	
	// right left 
	goForward = true;
	goBackwards = true;
	combo = 0;
	for (int i = 1; i < 4 && combo < 4; i++) {
		if (numberOfColumn + i > 6)
		{
			goForward = false;
		}
		if (numberOfColumn - i < 0)
		{
			goBackwards = false;
		}
		if (goForward && PlayBoard::GetInstance()->playBoard[numberOfColumn + i][numberOfRow] == playingChar) {
			combo++;
		}
		else {
			goForward = false;
		}
		if (goBackwards && PlayBoard::GetInstance()->playBoard[numberOfColumn - i][numberOfRow] == playingChar) {
			combo++;
		}
		else {
			goBackwards = false;
		}
		if (!goBackwards && !goForward)
		{
			break;
		}
	}
	if (combo >= 3)
		return true;

	//right up left down
	goForward = true;
	goBackwards = true;
	combo = 0;
	for (int i = 1; i < 4 && combo < 4; i++) {
		if (numberOfColumn + i > 6 || numberOfRow + i > 5)
		{
			goForward = false;
		}
		if (numberOfColumn - i < 0 || numberOfRow - i < 0)
		{
			goBackwards = false;
		}
		if (goForward && PlayBoard::GetInstance()->playBoard[numberOfColumn + i][numberOfRow + i] == playingChar) {
			combo++;
		}
		else {
			goForward = false;
		}
		if (goBackwards && PlayBoard::GetInstance()->playBoard[numberOfColumn - i][numberOfRow - i] == playingChar) {
			combo++;
		}
		else {
			goBackwards = false;
		}
		if (!goBackwards && !goForward)
		{
			break;
		}
	}
	if (combo >= 3)
		return true;

	// left up right down
	goForward = true;
	goBackwards = true;
	combo = 0;
	for (int i = 1; i < 4 && combo < 4; i++) {
		if (numberOfColumn + i > 6 || numberOfRow - i < 0)
		{
			goForward = false;
		}
		if (numberOfColumn - i < 0 || numberOfRow + i > 5)
		{
			goBackwards = false;
		}
		if (goForward && PlayBoard::GetInstance()->playBoard[numberOfColumn + i][numberOfRow - i] == playingChar) {
			combo++;
		}
		else {
			goForward = false;
		}
		if (goBackwards && PlayBoard::GetInstance()->playBoard[numberOfColumn - i][numberOfRow + i] == playingChar) {
			combo++;
		}
		else {
			goBackwards = false;
		}
		if (!goBackwards && !goForward)
		{
			break;
		}
	}
	if (combo >= 3)
		return true;

	//draw
	for (int i = 0; i < 7; i++)
		if (PlayBoard::GetInstance()->playBoard[i][5] == ' ')
			return false;
	return true;
}

bool PlayBoard::ValidPlace(int numberOfColumn, char playingCharacter)
{
	if (numberOfColumn>6 || numberOfColumn<0)
	{
		return false;
	}
	for (int i = 0; i < 6; i++)
	{
		if (PlayBoard::GetInstance()->playBoard[numberOfColumn][i] == ' ')
		{
			PlayBoard::GetInstance()->playBoard[numberOfColumn][i] = playingCharacter;
			return true;
		}
	}
	return false;
}

void PlayBoard::PrintMap()
{
	for (int i = 5; i >= 0; i--)
	{
		std::cout << "|\t";
		for (int j = 0; j < 7;j++) {
			std::cout << PlayBoard::GetInstance()->playBoard[j][i] << "\t|\t";
		}
		std::cout << "\n";
	}
	for (int i = 0; i < 113; i++)
		std::cout << "_";
	std::cout << "\n\t";
	for (int i = 0; i < 7; i++)
	{
		std::cout << i+1 << "\t\t";
	}
	std::cout << std::endl;
}

PlayBoard::PlayBoard(){}

void PlayBoard::resetBoard()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++) 
		{
			PlayBoard::GetInstance()->playBoard[i][j] = ' ';
		}
	}
}

