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
		cout << "\nWould you like to play a round? (Y/N):" << endl;
		cin >> menuchoice;

		menuchoice = toupper(menuchoice);

		cout << endl;

		switch (menuchoice)
		{
		case 'Y':
		{
			quit = Play21();

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

bool Blackjack::Play21()
{
	bool exit(false);
	bool Playerbusts(false);
	bool Dealerbusts(false);
	int PlayerHandValue(0);
	int DealerHandValue(0);
	bool StartDealerTurn(false);
	bool EndDealerTurn(false);
	int MoneyAtEndOfHand(0);

	//Make sure you can't bet over your limit and keep playing.
	mPlaya.Bet();

	//Every day I'm shufflin
	mDeck.Shuffle();
	
	cout << "\nYou have been dealt: " << endl;
	mPlaya.InitPlayerHand(*mDeck.Deal(), *mDeck.Deal());
	
	//mPlaya.AddCardToPHand(*mDeck.Deal());	//Display card
	//mPlaya.AddCardToPHand(*mDeck.Deal());	//Display card

	cout << "\nThe Dealer is showing: " << endl;
	mDeala.AddCardToDHand(*mDeck.Deal());

	cout << "\nYou currently have: " << mPlaya.GetPlayerHandValue() << endl;

	Check21(mPlaya.GetPlayerHandValue());
	Playerbusts = mPlaya.HitStay(mDeck, Playerbusts);
	
	cout << "You now have a current hand value of: " << mPlaya.GetPlayerHandValue() << endl;

	StartDealerTurn = Playerbusts;

	if (StartDealerTurn == false && EndDealerTurn == false)
	{
		cout << "\nThe dealer is now showing: " << endl;
		mDeala.AddCardToDHand(*mDeck.Deal()); //now

		Check21(mDeala.GetDealerHandValue());
		Dealerbusts = mDeala.DealerPlays21(mDeck, Dealerbusts);

		cout << "\nThe Dealer's hand has a value of: " << mDeala.GetDealerHandValue() << endl;
		
		EndDealerTurn = true;
		StartDealerTurn = true;
		//break;

		PlayerHandValue = mPlaya.GetPlayerHandValue();
		DealerHandValue = mDeala.GetDealerHandValue();

		if (Dealerbusts == true)
		{
			cout << "\nThe Dealer busted! Enjoy your winnings." << endl;
			mPlaya.AddMoney();	//double the wager amount here	
			mPlaya.AddMoney();	//So do it again to 2x wager?
		}

		else if (Playerbusts == true)
		{
			cout << "\nSorry, you busted so the dealer has won this round." << endl;
		}

		else
		{
			if (DealerHandValue < PlayerHandValue)
			{
				cout << "\nYou've won the round! Enjoy your winnings." << endl;
				mPlaya.AddMoney();	//double the wager amount here	
				mPlaya.AddMoney();	//So do it again to 2x wager?
			}

			else if (DealerHandValue == PlayerHandValue)
			{
				cout << "\nIt's a draw! (push)" << endl;
				mPlaya.AddMoney();	//Give back wager
			}

			else if (DealerHandValue > PlayerHandValue)
			{
				cout << "\nSorry, the dealer has won this round." << endl;
			}
		}
	}

	MoneyAtEndOfHand = mPlaya.GetMoneyAtEndOfHand();
	//Do you have to use GetBankRoll() below?
	if (MoneyAtEndOfHand == 0 || MoneyAtEndOfHand >= 50000)
	{
		cout << "Thanks for playing but come back another day." << endl;
		
		exit = true;
	}

	//Clear both of the hands.
	mPlaya.ClearHand();
	mDeala.DealerClearHand();

	return exit;
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