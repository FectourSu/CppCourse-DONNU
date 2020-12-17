#pragma once
#include "BasePlayer.h"
#include "Deck.h"
class Dealer : public  BasePlayer
{
private:
	std::string name;

public:
	Dealer(const std::string& name);
	void Move(Deck* deck);
	std::string getName();
};

