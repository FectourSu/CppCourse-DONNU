#include "Hand.h"

void Hand::addCard(Card* card)
{
	totalPoints += card->GetValue();
	cards.push_back(card);
}

int Hand::getTotal() const
{
	if (cards.empty())
	{
		throw std::exception("The hand is empty");
		return 0;
	}

	return this->totalPoints;
}

void Hand::clearCard()
{
	if (!cards.empty())
		for (auto card : cards)
			delete card;

	cards.clear();

	this->totalPoints = 0;
}



std::vector<Card*>& Hand::getCards()
{
	return this->cards;
}

Hand::~Hand()
{
	clearCard();
}

