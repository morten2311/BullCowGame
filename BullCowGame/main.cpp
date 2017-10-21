#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValiedGuess();
void PrintGuess(FText guess);
bool AskToPlayAgain();
void PrintGameSummary();

BullCowGame BCGame;

int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {

		FText Guess = GetValiedGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValiedGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cow = " << BullCowCount.Cows << "\n\n";

	}
	PrintGameSummary();
}

void PrintIntro(){
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "Well done - you win!";
	}
	else {
		std::cout << "Better luck next time !\n";
	}
}

FText GetValiedGuess(){
	EWordStatus Status = EWordStatus::Invalid;
	FText Guess = "";

	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " <<BCGame.GetMaxTries() << ". Enter your guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EWordStatus::OK:
			break;
		case EWordStatus::Not_Isogram:
			std::cout << "Please enter an isogram. \n";
			break;
		case EWordStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " Letter word. \n";
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Please enter a lowercase word. \n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EWordStatus::OK);
	return Guess;




}


void PrintGuess(FText guess) {
	std::cout << "Your guess was: " << guess << std::endl;

}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}
