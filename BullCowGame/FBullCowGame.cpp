#include "FBullCowGame.h"
#include <map>
#define Tmap std::map
using int32 = int;

void BullCowGame::Reset()
{
	bGameIsWon = false;

	MyCurrentTry = 1;

	const FString HIDDEN_WORD = "Planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

BullCowGame::BullCowGame()
{
	Reset();
}

bool BullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

int32 BullCowGame::GetMaxTries() const
{
	Tmap<int32, int32> WordLengthToMaxTries{ {3,5},{4,5},{5,5},{6,5} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}



int32 BullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 BullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}



EWordStatus BullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EWordStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess) ){
		return EWordStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EWordStatus::Wrong_Length;
	}
	else {
		EWordStatus::OK;
	}
} 

FBullCowCount BullCowGame::SubmitValiedGuess(FString Guess)
{
	MyCurrentTry++;

	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++) {
		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (Guess[i] == MyHiddenWord[j] ) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == HiddenWordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool BullCowGame::IsIsogram(FString String) const
{
	if (String.length() <= 1) {
		return true;
	}
	Tmap<char, bool> LetterSeen;
	for (auto Letter : String) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter] == false) {
			LetterSeen[Letter] = true;
		}
		else {
			return false;
		}

	}
	return true;
}

bool BullCowGame::IsLowercase(FString String) const
{
	for (auto Letter : String) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
