#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(int WordLength);
	int GetMaxTries();
	int GetCurrentTry();
	bool CheckGuess(std::string Guess);
	bool GameOver();

private:
	int CurrentTry = 1;
	int MaxTries = 5;
};
