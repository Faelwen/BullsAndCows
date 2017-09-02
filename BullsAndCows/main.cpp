#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

void PrintIntroduction();
int32 main();
void PlayGame();
FString GetValidGuess();
bool PlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int32 main() {
	do {
		PrintIntroduction();
		PlayGame();
	} while (PlayAgain());

	return 0;
}

void PlayGame() {
	int32 MaxTries = BCGame.GetMaxTries();

	while( !BCGame.GameOver() && BCGame.GetCurrentTry() <= MaxTries) {
		FString Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}

void PrintIntroduction() {
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
}

FString GetValidGuess() {
	EWordsStatus Status = EWordsStatus::Invalid_Status;
	FString Guess = "";

	do {
		std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << " - Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuess(Guess);
		switch (Status)
		{
		case EWordsStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EWordsStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EWordsStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			break;
		}
		std::cout << "\n";
	} while (Status != EWordsStatus::OK);

	return Guess;
}

bool PlayAgain() {
	BCGame.Reset();
	std::cout << "Do you want to play again?\n";
	FString Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'Y' || Response[0] == 'y');
}

void PrintGameSummary()
{
	if (BCGame.GameOver()) {
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else {
		std::cout << "Better lck next time!\n";
	}
	return;
}

