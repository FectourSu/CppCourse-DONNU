#pragma once
#include <iostream>
#include "Card.h"
class IFormattable
{
public:
	virtual ~IFormattable() {};
	virtual std::string format(const std::vector<Card*>& cards) = 0;
};