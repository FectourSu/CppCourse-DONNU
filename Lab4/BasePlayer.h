#pragma once
#include "Hand.h"
class BasePlayer
{
	Hand* hand;
public:
	BasePlayer()
	{
		hand = new Hand();
	}
	~BasePlayer()
	{
		delete hand;
	}
	Hand* GetHand()
	{
		return hand;
	}
};