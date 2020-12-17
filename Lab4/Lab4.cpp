#include <iostream>
#include "Game.h"
#include "Player.h"

int main()
{

	double bet;

	std::cout << "Your bet?" << std::endl;
	std::cin >> bet;
	
	auto player = new Player("Dmitry", bet);
	Game game(player);

	try
	{
		game.Play(bet);
		game.Dispose();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
			
		game.Dispose();
	}

	delete player;
}
