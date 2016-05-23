#include "Bankroll.h"

Bankroll::Bankroll() : money(1000)
{ }

Bankroll::~Bankroll()
{ }

void Bankroll::BetMoney(int wager)
{
	money -= wager;
}

void Bankroll::AddMoney(int wager)
{
	money += wager;
}

int Bankroll::GetMoney() const
{
	return money;
}