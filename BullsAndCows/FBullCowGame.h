#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(int WordLength);
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool CheckGuess(std::string Guess);
	bool GameOver() const;

private:
	int CurrentTry = 1;
	int MaxTries = 5;
};
