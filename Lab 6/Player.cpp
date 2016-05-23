#include "Player.h"

/****************************************************************************
Purpose: Default Constructor.

Entry: Nothing.

Exit: A constructor that can be called without any parameters.
*****************************************************************************/
Player::Player() : mWager(0)
{	}

/****************************************************************************
Purpose: Dtor.

Entry: Nothing.

Exit: Invoked when an object is destoryed to free up allocated space.
*****************************************************************************/
Player::~Player()
{	}

/****************************************************************************
Purpose: Initialize the player's Hand.

Entry: Pass in two Cards that is to be dealt to the player.

Exit: Added two Cards to the player's Hand and calculated the value of the Hand.
*****************************************************************************/
void Player::InitPlayerHand(Card card1, Card card2)
{
	mPlayerHand.AddCardToHand(card1);
	mPlayerHand.AddCardToHand(card2);

	mPlayerHand.CountHandValue();
}

/****************************************************************************
Purpose: Bet function to determine how much the player can wager.

Entry: Nothing.

Exit: Player has bet a certain amount of their money.
*****************************************************************************/
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

/****************************************************************************
Purpose: Checks player's bankroll the make sure they can double down or not.

Entry: Nothing.

Exit: Return a bool for the program to know if the player can double down or not.
*****************************************************************************/
bool Player::CheckDoubleDownWager()
{
	bool WagerCanDouble(false);

	if (mWager <= GetBankroll().GetMoney())
	{
		WagerCanDouble = true;
	}

	return WagerCanDouble;
}

/****************************************************************************
Purpose: After the player has chosen the double down capability, double the 
wager they bet at the beginning of the round.

Entry: Nothing.

Exit: Bets the same amount that the player has at the beginning of the round
and then double the wager so that if they win, they win double the amount.
*****************************************************************************/
void Player::DoubleTheWager()
{
	mBankroll.BetMoney(mWager);

	mWager = mWager * 2;
	//mWager += mWager;
}

/****************************************************************************
Purpose: Getter for player's bankroll/money.

Entry: Nothing.

Exit: return mBankroll.
*****************************************************************************/
Bankroll Player::GetBankroll() const
{
	return mBankroll;
}

/****************************************************************************
Purpose: Call the bankroll's add money function.

Entry: Nothing.

Exit: Add in player's wager back into the bankroll.
*****************************************************************************/
void Player::AddMoney()
{
	mBankroll.AddMoney(mWager);
}

/****************************************************************************
Purpose: Getter for player's Hand.

Entry: Nothing.

Exit: return mPlayerHand.
*****************************************************************************/
Hand Player::GetPlayerHand() const
{
	return mPlayerHand;
}

/****************************************************************************
Purpose: Add a Card to player's Hand.

Entry: a Card.

Exit: Added a Card to player's Hand then recalculated player's Hand value.
*****************************************************************************/
void Player::AddCardToPHand(Card mCard)
{
	mPlayerHand.AddCardToHand(mCard);
	
	mPlayerHand.CountHandValue();
}

/****************************************************************************
Purpose: Getter for player's Hand value.

Entry: Nothing.

Exit: return the value of player's Hand.
*****************************************************************************/
int Player::GetPlayerHandValue() const
{
	return mPlayerHand.GetHandValue();
}

/****************************************************************************
Purpose: Hit or Stay function for the player.

Entry: Deck and a bool to be able to deal Cards and check if the player busts.

Exit: The player is given a choice to hit or stay as long as they did not hit
blackjack from the first two cards of their Hand. They can continue to hit as
long as they do not bust (hand value > 21) or stay their Hand. Calculates if
the player has hit 21 or busted.
*****************************************************************************/
bool Player::HitStay(Deck & mDeck, bool mBusts)
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
			PlayerHit(*mDeck.Deal());

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

/****************************************************************************
Purpose: Player has chosen the Hit option.

Entry: a Card to be dealt.

Exit: Call the Hand's AddCardToHand function to add a Card to player's Hand.
*****************************************************************************/
void Player::PlayerHit(Card mCard)
{
	mPlayerHand.AddCardToHand(mCard);
}

/****************************************************************************
Purpose: Reset the value of the Hand.

Entry: Nothing.

Exit: Pass in a 0 so that the Hand value is reset.
*****************************************************************************/
void Player::ResetHandValue()
{
	mPlayerHand.SetHandValue(0);
	//maybe pass in a 0 and then pass in an int to SetHandValue?
}

/****************************************************************************
Purpose: Clear the Hand.

Entry: Nothing.

Exit: Call Hand's Dtor to delete the Hand.
*****************************************************************************/
void Player::ClearHand()
{
	mPlayerHand.~Hand();
}

/****************************************************************************
Purpose: Getter for player's money/bankroll at the end of the round.

Entry: Nothing.

Exit: return player's bankroll/money.
*****************************************************************************/
int Player::GetMoneyAtEndOfHand()
{
	return GetBankroll().GetMoney();
}