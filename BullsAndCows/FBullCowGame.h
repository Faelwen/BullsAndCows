#pragma once

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordsStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame();
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool GameOver() const;
	EWordsStatus CheckGuess(FString) const;
	void Reset();
	FBullCowCount SubmitGuess(FString);

private:
	int32 CurrentTry;
	FString HiddenWord;
	bool bGameWon;
	bool IsLowerCase(FString) const;
	bool IsIsogram(FString) const;
};
