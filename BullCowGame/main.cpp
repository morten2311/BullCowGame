#include <iostream>
#include <string>
using namespace std;
void PrintIntro();
string GetGuessAndPrintBack();

int main()
{
	PrintIntro();
	constexpr int NR_OF_GUESSES = 10;
	for (int i = 0; i < NR_OF_GUESSES; i++){
		GetGuessAndPrintBack();
		cout << endl;
	}
}

void PrintIntro(){
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game. \n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

string GetGuessAndPrintBack(){
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}