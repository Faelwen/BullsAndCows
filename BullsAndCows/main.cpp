#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntroduction();
int main();
void PlayGame();
std::string GetGuess();
bool PlayAgain();

FBullCowGame BCGame;

int main() {
	do {
		PrintIntroduction();
		PlayGame();
	} while (PlayAgain());

	return 0;
}

void PlayGame() {
	int MaxTries = BCGame.GetMaxTries();

	for (int count = 1; count <= MaxTries; count++)	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was:" << Guess << std::endl;
		std::cout << std::endl;
	}
}

void PrintIntroduction() {
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
}

std::string GetGuess() {
	std::cout << "Try " << BCGame.GetCurrentTry() << " - Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool PlayAgain() {
	std::cout << "Do you want to play again?" << std::endl;
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'Y' || Response[0] == 'y');
}

