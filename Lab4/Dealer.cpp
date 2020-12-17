#include "Dealer.h"


Dealer::Dealer(const std::string& name) : name(name)
{
}

void Dealer::Move(Deck* deck)
{
	this->GetHand()->addCard(deck->getCards());

	if (this->GetHand()->getTotal() > 21)
		return;
}

std::string Dealer::getName()
{
    return this->name;
}
