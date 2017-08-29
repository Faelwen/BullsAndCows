#include <iostream>
#include <string>

using namespace std;

int main()
{
	constexpr int WORD_LENGTH = 5;

	// Introduce the game
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;

	// Get a guess from the user
	cout << "Enter your guess: ";
	string Guess = "";
	cin >> Guess;

	// Repeat the guess back to the user
	cout << "Your guess was: " << Guess << endl;

	// Get a guess from the user
	cout << "Enter your guess: ";
	cin >> Guess;

	// Repeat the guess back to the user
	cout << "Your guess was: " << Guess << endl;

	return 0;
}