#pragma once
#include "BasePlayer.h"
#include <string>

class Player : public BasePlayer
{
	std::string name;

	double bet = 0;
	double balance = bet;

public:
	Player(const std::string& name, const double& bet);

	double getBalance();
	std::string getName();
	void reward(double& bet);
	void further(double& bet);
};

