#include "Player.h"

Player::Player(const std::string& name,const double& bet) 
    : name(name), bet(bet)
{
}

double Player::getBalance()
{
    return this->balance;
}

std::string Player::getName()
{
    return this->name;
}


void Player::reward(double& balance)
{
    this->GetHand()->getTotal();
    this->balance = bet * 2;
}

void Player::further(double& balance)
{
    this->balance = bet / 2;
}
