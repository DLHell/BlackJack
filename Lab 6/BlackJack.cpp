#include "BlackJack.h"
//#include "Deck.h"
//#include "Player.h"
//#include "Dealer.h"

Blackjack::Blackjack() : mPlaya(), mDeala(), mDeck()
{
	/*Player();
	Dealer();
	Deck();*/
}

Blackjack::~Blackjack()
{

}

void Blackjack::MainMenu()
{
	char menuchoice = NULL;
	bool quit(false);

	cout << "Welcome to Blackjack!" << endl;

	while (quit == false)
	{
		cout << "Would you like to play a round? (Y/N):" << endl;
		cin >> menuchoice;

		menuchoice = toupper(menuchoice);

		cout << endl;

		switch (menuchoice)
		{
		case 'Y':
		{
			Play21();

			break;
		}

		case 'N':
		{
			cout << "Thanks for stopping by, see you later!" << endl;

			quit = true;

			break;
		}

		default:
			cout << "Sorry, that was not a valid menu option, please try again.\n" << endl;
		}
	}
}

void Blackjack::Play21()
{
	bool exit(false);
	bool Playerbusts(false);
	//int PlayerHandValue(0);
	//int DealerHandValue(0);

	mPlaya.Bet();

	//Every day I'm shufflin
	mDeck.Shuffle();
	
	cout << "\nYou have been dealt: " << endl;
	mPlaya.InitPlayerHand(*mDeck.Deal(), *mDeck.Deal());
	
	//mPlaya.AddCardToPHand(*mDeck.Deal());	//Display card
	//mPlaya.AddCardToPHand(*mDeck.Deal());	//Display card

	cout << "\nThe Dealer is showing: " << endl;
	mDeala.AddCardToDHand(*mDeck.Deal());
	//mDeala.AddCardToDHand(*mDeck.Deal()); later

	cout << "\nYou currently have: " << mPlaya.GetPlayerHandValue() << endl;

	Check21(mPlaya.GetPlayerHandValue());
	Playerbusts = mPlaya.HitStay(mDeck, Playerbusts);
	//cout << "current hand value: " << mPlaya.GetPlayerHandValue() << endl;

	if (!Playerbusts)
	{
		cout << "\nThe dealer is now showing: " << endl;
		mDeala.AddCardToDHand(*mDeck.Deal()); //now

		Check21(mDeala.GetDealerHandValue());

	}

	//*Flip* Dealer's hidden card.
	////mDeala.AddCardToDHand(*mDeck.Deal()); later
	//DealerHandValue = dcard1value + dcard2value;
	//Check here to see if Dealer is below 17. If so, hit until 17.
	//DealerHitStay();
	//Check21();

	//BustOrNah();	//Is this a Blackjack function?
	//Check if DealerHandValue > 21;

	//Can you make BustOrNah and Check21 the same function?

	/*PlayerHandValue = mPlaya.GetPlayerHandValue();
	DealerHandValue = mDeala.GetDealerHandValue();

	if (DealerHandValue < PlayerHandValue)
	{
	cout << "You've won the round! Enjoy your winnings." << endl;
	AddMoney();	//double the wager amount here
	end round. (Do you have to destory deck here?)
	}

	else if (DealerHandValue == PlayerHandValue)
	{
	cout << "It's a draw!" << endl;
	AddMoney(wager);	//Give back wager

	else if (DealerHandValue > PlayerHandValue)
	{
	cout << "Sorry, the dealer has won this round." << endl;
	take money here.	//So do nothing?
	end round. (Do you have to destory deck here?)
	}
	*/

	/*
	//Do you have to use GetBankRoll() below?
	/*if (mPlaya.mBankroll == 0 || mPlaya.mBankroll >= 50000)
	{
	cout << "Thanks for playing but come back another day." << endl;
	exit = true;
	}*/
}

//bool Blackjack::GoAgain(bool & exit)
//{
//	//char choice = '\0';
//	int choice = 0;
//
//	Prompt();
//
//	cout << "Please enter your menu choice: ";
//	cin >> choice;
//
//	//choice = toupper(choice);
//
//	cout << endl;
//
//	switch (choice)
//	{
//		case 1:
//		{
//			exit = false;
//
//			break;
//		}
//
//		case 2:
//		{
//			exit = true;
//
//			break;
//		}
//
//		default:
//			cout << "Sorry, that was not a valid menu option, please try again.\n" << endl;
//	}
//
//	return exit;
//}

void Blackjack::Prompt()
{
	cout << "\nWould you like to play another hand: " << endl;
	cout << "\n1) Yes." << endl;
	cout << "2) No.\n" << endl;
}

void Blackjack::Check21(int handvalue)
{
	if (handvalue == 21)
	{
		cout << "You hit BlackJack! Stay your hand." << endl;
	}
}

void Blackjack::BustOrNah(int bustmate)
{
	if (bustmate > 21)
	{
		cout << "Sorry mate, you just busted." << endl;
	}
}