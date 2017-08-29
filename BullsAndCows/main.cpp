#include <iostream>
#include <string>

using namespace std;

void PrintIntroduction();
string GetGuess();


int main()
{
	PrintIntroduction();
	GetGuess();
	return 0;
}

void PrintIntroduction() {
	// Introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;
}

string GetGuess() {
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	cout << "Your guess was:" << Guess << endl;
	return Guess;
}