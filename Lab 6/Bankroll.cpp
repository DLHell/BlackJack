#include "Bankroll.h"


Bankroll::Bankroll() : money(1000)
{	}

/****************************************************************************
Purpose: Dtor.

Entry: Nothing.

Exit: Invoked when an object is destoryed to free up allocated space.
*****************************************************************************/
Bankroll::~Bankroll()
{	}

/****************************************************************************
Purpose: Betting a certain amount of money.

Entry: Int value that represents the player's wager.

Exit: subtract the wager amount from the player's bankroll.
*****************************************************************************/
void Bankroll::BetMoney(int wager)
{
	money -= wager;
}

/****************************************************************************
Purpose: Add in a certain amount of money.

Entry: Int vaue that represents the palyer's wager.

Exit: Add in the wager amount to the player's bankroll.
*****************************************************************************/
void Bankroll::AddMoney(int wager)
{
	money += wager;
}

/****************************************************************************
Purpose: Getter for player's bankroll.

Entry: Nothing.

Exit: return money.
*****************************************************************************/
int Bankroll::GetMoney() const
{
	return money;
}