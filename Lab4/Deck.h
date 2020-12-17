#pragma once
#include <vector>
#include <algorithm>
#include "Card.h"
#include <random>
#include <ctime>
class Deck
{
	std::vector<Card*> cards;
	
public:
	~Deck();
	Deck();
	void shuffle();
	void fillCard();
	void clearCard();

	int getCount();
	Card*& getCards();
	
};

