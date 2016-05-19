#include "Player.h"

Player::Player()// : money(1000)
{ }

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

Hand Player::GetPlayerHand() const
{
	return mPlayerHand;
}

//void Player::AddCardToPHand(Card mCard)
//{
//	//mPlayerHand.CountHandValue();
//	//GetHandValue();
//	
//	mCard.Display();
//	//How to I really add to a hand and make sure the program
//	//knows the value of my hand?
//}

int Player::GetPlayerHandValue() //const
{
	//mPlayerHand.CountHandValue();

	return mPlayerHand.GetHandValue();
}

//maybe change to two functions
void Player::HitStay(Card mCard)	//Make a bool and make this function return a bool?
{
	char hitchoice = NULL;
	bool hitornay(false);

	while (hitornay == false)
	{
		cout << "\nWould you like to hit or stay? (y/n)" << endl;
		cin >> hitchoice;

		hitchoice = toupper(hitchoice);

		cout << endl;

		switch (hitchoice)
		{
		case 'Y':
		{
			PlayerHit(mCard);	//How to access deck now?

			mPlayerHand.CountHandValue();

			break;
		}

		case 'N':
		{
			//Nothing here since player chose to stay
			//mCard.SetDealt(false);
			//PlayerStay();
			hitornay = true;

			break;
		}

		default:
			cout << "Sorry, that was not a valid menu option, please try again.\n" << endl;
		}
	}
}

void Player::PlayerHit(Card mCard)
{
	mPlayerHand.AddCardToHand(mCard);
}

//void Player::PlayerStay()
//{
//
//}