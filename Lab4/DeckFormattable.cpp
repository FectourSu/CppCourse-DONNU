#include "DeckFormattable.h"


std::string DeckFormattable::format(const std::vector<Card*>& cards)
{
	std::string result = "";

	for (auto card : cards)
		result += card->ToString() + " ";

	return result;
}
