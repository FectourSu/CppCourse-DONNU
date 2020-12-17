#include "Card.h"

int Card::GetValue() const
{
    if (isFaceUp)
        if (this->rank > 10)
            return 10;
    
    return static_cast<int>(this->rank);
}

void Card::Flip()
{
    this->isFaceUp = !isFaceUp;
}

Card::Card(Card::Rank rank, Card::Suit suit, bool isFaceUp)
    : rank(rank), suit(suit), isFaceUp(isFaceUp)
{
}



Card::Rank Card::getRank()
{
    return this->rank;
}

Card::Suit Card::getSuit()
{
    return this->suit;
}
std::string Card::ToString()
{
	const std::string ranks[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9",
	"10", "J", "Q", "K" };

	char suits[] = { 3, 4, 5, 6 };

	return ranks[this->rank - 1] + (char)suits[this->suit];
}
std::ostream& operator<<(std::ostream& os, Card& aCard)
{
	if (aCard.isFaceUp)
		os << aCard.ToString();
	else
		os << "??";
	return os;
}