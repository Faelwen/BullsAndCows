#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame();
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool GameOver() const;

	bool CheckGuess(FString Guess);
	void Reset();
	

private:
	int32 CurrentTry;
	int32 MaxTries;
};
