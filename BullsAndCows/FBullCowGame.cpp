#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const {
	return MaxTries;
}

int32 FBullCowGame::GetCurrentTry() const {
	return CurrentTry;
}

bool FBullCowGame::GameOver() const {
	return false;
}

bool FBullCowGame::CheckGuess(FString Guess) {
	return false;
}

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	MaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	HiddenWord = HIDDEN_WORD;

	CurrentTry = 1;
	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	CurrentTry++;
	FBullCowCount BullCowCount;

	for (int32 i = 0; i < HiddenWord.length(); i++) {
		for (int32 j = 0; j < HiddenWord.length(); j++) {
			if (Guess[i] == HiddenWord[i]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}