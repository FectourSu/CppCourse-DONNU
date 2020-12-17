#pragma once
#include <iostream>
#include <vector>
#include "IFormattable.h"
#include "Card.h"
class DeckFormattable : public IFormattable
{
	std::vector<Card*> cards;

public:
	std::string format(const std::vector<Card*>& cards);
};

