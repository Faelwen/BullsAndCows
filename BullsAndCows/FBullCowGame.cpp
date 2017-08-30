#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

int FBullCowGame::GetMaxTries() const {
	return MaxTries;
}

int FBullCowGame::GetCurrentTry() const {
	return CurrentTry;
}

bool FBullCowGame::GameOver() const {
	return false;
}

bool FBullCowGame::CheckGuess(std::string Guess) {
	return false;
}

void FBullCowGame::Reset() {
	constexpr int MAX_TRIES = 8;
	CurrentTry = 1;
	MaxTries = MAX_TRIES;
	return;
}
