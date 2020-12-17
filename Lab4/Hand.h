#pragma once
#include "Card.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
class Hand
{
	std::vector<Card*> cards;
	int totalPoints = 0;

public:
	void addCard(Card* card);
	int getTotal() const;
	void clearCard();

	std::vector<Card*>& getCards();

	virtual ~Hand();
};

