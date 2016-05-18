#include "Player.h"

Player::Player()// : money(1000)
{ }

Player::~Player()
{ }

void Player::Bet()
{
	int wager = 0;

	cout << "You currently have: $" << GetBankroll().GetMoney() << endl;
	
	cout << "How much would you like to wager: ";
	cin >> wager;

	cout << endl;

	mBankroll.BetMoney(wager);
}

Bankroll Player::GetBankroll() const
{
	return mBankroll;
}

void Player::AddCardToPHand(Card mCard)
{
	
	
	//Card mCard;
	//below function call does not work, make a getter for mDeck?
	//mDeck.Deal().Display();
	mCard.Display();
	//How to I really add to a hand and make sure the program
	//knows the value of my hand?
}

int Player::GetHandValue() const
{
	

	return mPlayerHand.GetHandValue();
}

void Player::HitStay()	//Make a bool and make this function return a bool?
{
	/*
	This would have the same problem as GoAgain currently
	char hitchoice = NULL;
	bool hitornay(false);

	while (hitornay == false)
	{
	cout << "Would you like to hit or stay? (y/n)" << endl;
	cin >> hitchoice;

	hitchoice = toupper(hitchoice);

	switch (hitchoice)
	{
	case 'Y':
	{
	AddCardtoPHand();

	break;
	}

	case 'N':
	{
	//Player has chosen to stay

	quit = true;

	break;
	}

	default:
	cout << "Sorry, that was not a valid menu option, please try again.\n" << endl;
	}
	
	*/
}