#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool GameOver() const;
	bool CheckGuess(FString) const;

	void Reset();
	FBullCowCount SubmitGuess(FString);

private:
	int32 CurrentTry;
	int32 MaxTries;
	FString HiddenWord;
};
