#pragma once
#include "Card.h"
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <iostream>
#include "IFormattable.h"
#include "DeckFormattable.h"
#include "BasePlayer.h"
class Game
{
	Deck* deck;
	Dealer* dealer;
	Player* player;

	void prettyPrint(IFormattable& format);


	bool ExcessScore(BasePlayer* hand);

	double balance = 0;

public:

	void Play(double& bet);

	void Dispose();

	Game(Player* player);
	virtual ~Game();
};

