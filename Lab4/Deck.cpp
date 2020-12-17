#include "Deck.h"

Deck::~Deck()
{
	clearCard();
}

Deck::Deck()
{
	cards.reserve(52);
	shuffle();
}

void Deck::clearCard()
{
	if (!cards.empty())
		for (auto card : cards)
			delete card;

	cards.clear();
}

void Deck::shuffle()
{
	srand(time(NULL));
	std::random_shuffle(cards.begin(), cards.end());
}

void Deck::fillCard()
{
	for (int s = Card::Hearts; s <= Card::Spades; ++s)
		for (int r = Card::Ace; r <= Card::King; ++r)
			this->cards.push_back(new Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s), true));
}

int Deck::getCount()
{
	return cards.size();
}

Card*& Deck::getCards()
{
	if (cards.empty())
		throw std::exception("The deck is empty");

	auto card = cards.back();

	cards.pop_back();

	return card;
}
