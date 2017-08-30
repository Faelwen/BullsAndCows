#include <iostream>
#include <string>

using namespace std;

void PrintIntroduction();
int main();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();


int main()
{
	PrintIntroduction();
	PlayGame();
	AskToPlayAgain();
	return 0;
}

void PlayGame() {
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		cout << "Your guess was:" << Guess << endl;
		cout << endl;
	}
}

void PrintIntroduction() {
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;
}

string GetGuess() {
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again?" << endl;
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'Y' || Response[0] == 'y');
}

