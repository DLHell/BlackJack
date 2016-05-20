#include "Bankroll.h"

Bankroll::Bankroll() : money(1000)
{ }

Bankroll::~Bankroll()
{ }

void Bankroll::BetMoney(int wager)
{
	//if (wager > money)
	//{
	//	cout << "Sorry, you are short of your wager." << endl;
	//}
	////How do I not allow them to bet more than allowed?
	////switch statement here too? should do the same for below condition


	//else if (wager <= 0)
	//{
	//	cout << "Nice try but your wager can't be less than or equal to zero." << endl;
	//}

	//else
	//{
		money -= wager;
	//}
}

void Bankroll::AddMoney(int wager)
{
	money += wager;
}

int Bankroll::GetMoney() const
{
	return money;
}