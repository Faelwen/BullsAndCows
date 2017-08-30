#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame();
	
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool GameOver() const;

	bool CheckGuess(std::string Guess);
	void Reset();
	

private:
	int CurrentTry;
	int MaxTries;
};
