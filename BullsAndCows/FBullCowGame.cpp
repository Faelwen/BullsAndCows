#include "FBullCowGame.h"

void FBullCowGame::Reset(int WordLength)
{
}

int FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return CurrentTry;
}

bool FBullCowGame::CheckGuess(std::string Guess)
{
	return false;
}

bool FBullCowGame::GameOver() const
{
	return false;
}
