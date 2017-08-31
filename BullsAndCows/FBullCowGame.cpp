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
	CurrentTry = 1;
	MaxTries = MAX_TRIES;
	return;
}
