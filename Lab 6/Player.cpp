#include "Player.h"


/****************************************************************************
Purpose: Default Constructor.

Entry: Nothing.

Exit: A constructor that can be called without any parameters.
*****************************************************************************/
Player::Player() : mWager(0)
{ }


/****************************************************************************
Purpose: Dtor.

Entry: Nothing.

Exit: A constructor that can be called without any parameters.
*****************************************************************************/
Player::~Player()
{ }

void Player::InitPlayerHand(Card card1, Card card2)
{
	mPlayerHand.AddCardToHand(card1);
	mPlayerHand.AddCardToHand(card2);

	mPlayerHand.CountHandValue();
}

void Player::Bet()
{
	cout << "You currently have: $" << GetBankroll().GetMoney() << endl;

	cout << "How much would you like to wager: ";
	cin >> mWager;

	cout << endl;

	if (mWager > GetBankroll().GetMoney())
	{
		cout << "Sorry, you are short of your wager." << endl;

		Bet();
	}

	else if (mWager <= 0)
	{
		cout << "Nice try but your wager can't be less than or equal to zero." << endl;

		Bet();
	}

	else
	{
		mBankroll.BetMoney(mWager);
	}
}

bool Player::CheckDoubleDownWager()
{
	bool WagerCanDouble(false);

	if (mWager <= GetBankroll().GetMoney())
	{
		WagerCanDouble = true;
	}

	return WagerCanDouble;
}

void Player::DoubleTheWager()
{
	mBankroll.BetMoney(mWager);

	mWager = mWager * 2;
	//mWager += mWager;
}

Bankroll Player::GetBankroll() const
{
	return mBankroll;
}

void Player::AddMoney()
{
	mBankroll.AddMoney(mWager);
}

Hand Player::GetPlayerHand() const
{
	return mPlayerHand;
}

void Player::AddCardToPHand(Card mCard)
{
	mPlayerHand.AddCardToHand(mCard);
	
	mPlayerHand.CountHandValue();
}

int Player::GetPlayerHandValue() const
{
	return mPlayerHand.GetHandValue();
}

bool Player::HitStay(Deck & mDeck, bool mBusts)	//Make a bool and make this function return a bool?
{
	char hitchoice = NULL;
	bool hitornay(false);
	bool busts(false);

	while (GetPlayerHandValue() < 21 && hitornay == false)
	{
		cout << "\nWould you like to hit or stay? (y/n)" << endl;
		cin >> hitchoice;

		hitchoice = toupper(hitchoice);

		cout << endl;

		switch (hitchoice)
		{
		case 'Y':
		{
			PlayerHit(*mDeck.Deal());	//How to access deck now?

			mPlayerHand.CountHandValue();
		
			break;
		}

		case 'N':
		{
			hitornay = true;

			break;
		}

		default:
			cout << "Sorry, that was not a valid menu option, please try again.\n" << endl;
		}
	}

	if (GetPlayerHandValue() == 21)
	{
		cout << "You have 21, stay." << endl;
	}

	else if (GetPlayerHandValue() > 21)
	{
		cout << "You busted bruh.\n" << endl;

		busts = true;
	}

	return busts;
}

void Player::PlayerHit(Card mCard)
{
	mPlayerHand.AddCardToHand(mCard);
}

void Player::ResetHandValue()
{
	mPlayerHand.SetHandValue(0);
	//maybe pass in a 0 and then pass in an int to SetHandValue?
}

void Player::ClearHand()
{
	mPlayerHand.~Hand();
}

int Player::GetMoneyAtEndOfHand()
{
	return GetBankroll().GetMoney();
}