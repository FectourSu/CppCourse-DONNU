#include "Game.h"

void Game::Play(double& bet)
{
	this->deck->fillCard();

	this->deck->shuffle();

	std::string command = "";

	DeckFormattable df;
	
	do
	{
		player->GetHand()->addCard(deck->getCards());

		dealer->Move(deck);

		prettyPrint(df);

		std::cin >> command;

		if (this->ExcessScore(dealer) && this->ExcessScore(player) || 
			player->GetHand()->getTotal() > 21 
			&& dealer->GetHand()->getTotal() > 21)
		{
			std::cout << "Dead heat!" << std::endl;
			break;
		}
		if (dealer->GetHand()->getTotal() > 21
			|| this->ExcessScore(player))
		{
			std::cout << "You win!" << std::endl;
			this->player->reward(bet);
			break;
		}
		if (player->GetHand()->getTotal() > 21 
			|| this->ExcessScore(dealer))
		{
			std::cout << "You lose!" << std::endl;
			this->player->further(bet);
			break;
		}

		if (player->getBalance() <= 0)
		{
			std::cout << "Your balance is empty";
			break;
		}

	} while (command != "n");
	
	std::cout << "Balance: " << player->getBalance() << std::endl << std::endl;
}

void Game::prettyPrint(IFormattable& object)
{
	std::cout << "\nDecks: " << "[" << deck->getCount() << "]" << std::endl;

	std::cout << dealer->getName() + ": "<< object.format(dealer->GetHand()->getCards()) 
		<< ": " << dealer->GetHand()->getTotal() << std::endl;

	std::cout << player->getName() + ": " << object.format(player->GetHand()->getCards()) 
		<< ": " << player->GetHand()->getTotal() << std::endl;

	std::cout << "Continue?" << std::endl;

}

bool Game::ExcessScore(BasePlayer* player)
{
	return player->GetHand()->getTotal() == 21;
}

void Game::Dispose()
{
	this->player->GetHand()->clearCard();

	this->dealer->GetHand()->clearCard();

	this->deck->clearCard();
}

Game::Game(Player* player)
{
	this->player = player;

	this->dealer = new Dealer("Dealer");

	this->deck = new Deck();

	this->balance = player->getBalance();
}

Game::~Game()
{
	delete this->dealer;
	delete this->deck;
}
