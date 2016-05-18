#include "Bankroll.h"

Bankroll::Bankroll() : money(1000)
{ }

Bankroll::~Bankroll()
{ }

void Bankroll::BetMoney(int wager)
{
	if (wager > money)
	{
		cout << "Sorry, you are short of your wager." << endl;
	}

	else if (wager <= 0)
	{
		cout << "Nice try but your wager can't be less than or equal to zero." << endl;
	}

	else
	{
		money -= wager;
	}
}

int Bankroll::GetMoney() const
{
	return money;
}