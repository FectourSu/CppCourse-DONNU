#pragma once
#include <windows.h>
#include <iostream>
class Card
{
public:
	enum Rank { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
	enum Suit { Hearts, Dimond, Clubs, Spades };

	int GetValue() const;
	void Flip();
	Card(Rank rank, Suit suit, bool isFaceUp);

	std::string ToString();

	Rank getRank();
	Suit getSuit();

	friend std::ostream& operator<<(std::ostream& os, 
		Card& aCard);

private:
	Card::Rank rank;
	Card::Suit suit;

	bool isFaceUp;
};

