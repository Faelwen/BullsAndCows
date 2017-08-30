#include "FBullCowGame.h"

void FBullCowGame::Reset(int WordLength)
{
}

int FBullCowGame::GetMaxTries()
{
	return MaxTries;
}

int FBullCowGame::GetCurrentTry()
{
	return CurrentTry;
}

bool FBullCowGame::CheckGuess(std::string Guess)
{
	return false;
}

bool FBullCowGame::GameOver()
{
	return false;
}
