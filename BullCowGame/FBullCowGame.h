#pragma once
#include <string>
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EWordStatus {
	OK, 
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Invalid
};
class BullCowGame {

public:
	BullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EWordStatus CheckGuessValidity(FString) const;
	bool IsGameWon() const;

	void Reset();

	FBullCowCount SubmitValiedGuess(FString);


private:
	bool IsIsogram(FString string) const;
	bool IsLowercase(FString) const;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
};