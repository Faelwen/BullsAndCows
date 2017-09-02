#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() {
	Reset();
}
int32 FBullCowGame::GetMaxTries() const {
	TMap <int32, int32> WordLengthToMaxTries{ {3,4}, {4, 7}, {5, 10}, {6, 15}, {7, 20} };
	return WordLengthToMaxTries[HiddenWord.length()];
}
int32 FBullCowGame::GetCurrentTry() const {
	return CurrentTry;
}
int32 FBullCowGame::GetHiddenWordLength() const
{
	return HiddenWord.length();
}
bool FBullCowGame::GameOver() const {
	return bGameWon;
}

EWordsStatus FBullCowGame::CheckGuess(FString Guess) const {
	if (!IsIsogram(Guess)) {
		return EWordsStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) {
		return EWordsStatus::Not_Lowercase;
	}
	else if (GetHiddenWordLength() != Guess.length()) {
		return EWordsStatus::Wrong_Length;
	}
	else {
		return EWordsStatus::OK;
	}
}

void FBullCowGame::Reset() {
	const FString HIDDEN_WORD = "planet";
	HiddenWord = HIDDEN_WORD;
	CurrentTry = 1;
	bGameWon = false;
	return;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word) {
		if (!islower(Letter)) { return false; }
	}
	return true;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	CurrentTry++;
	FBullCowCount BullCowCount;

	for (int32 i = 0; i < GetHiddenWordLength(); i++) {
		for (int32 j = 0; j < (int32)Guess.length(); j++) {
			if (Guess[j] == HiddenWord[i]) {
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

	if (BullCowCount.Bulls == GetHiddenWordLength()) {
		bGameWon = true;
	}
	else {
		bGameWon = false;
	}
	return BullCowCount;
}
