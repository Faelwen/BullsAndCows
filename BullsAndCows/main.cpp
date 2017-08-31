#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

void PrintIntroduction();
int32 main();
void PlayGame();
FString GetGuess();
bool PlayAgain();

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

	for (int32 count = 1; count <= MaxTries; count++)	{
		FString Guess = GetGuess();
		std::cout << "Your guess was:" << Guess << std::endl;
		std::cout << std::endl;
	}
}

void PrintIntroduction() {
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
}

FString GetGuess() {
	std::cout << "Try " << BCGame.GetCurrentTry() << " - Enter your guess: ";
	FString Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool PlayAgain() {
	BCGame.Reset();
	std::cout << "Do you want to play again?" << std::endl;
	FString Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'Y' || Response[0] == 'y');
}

