#include "BlackJack.h"

/****************************************************************************
Purpose: Default Constructor.

Entry: Nothing.

Exit: A constructor that can be called without any parameters.
*****************************************************************************/
Blackjack::Blackjack() : mPlaya(), mDeala(), mDeck()
{	}

/****************************************************************************
Purpose: Dtor.

Entry: Nothing.

Exit: Invoked when an object is destoryed to free up allocated space.
*****************************************************************************/
Blackjack::~Blackjack()
{	}

/****************************************************************************
Purpose: Main Menu.

Entry: Nothing.

Exit: Asks user if they want to play a round of blackjack.
*****************************************************************************/
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

/****************************************************************************
Purpose: Main Driver.

Entry: Nothing.

Exit: Runs the blackjack program.
*****************************************************************************/
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
	int DoubleDownOption(0);
	bool DoubleDownWager(false);
	bool DoubleDownOrNah(false);

	//Make sure you can't bet over your limit and keep playing.
	mPlaya.Bet();

	//Every day I'm shufflin
	mDeck.Shuffle();
	
	cout << "\nYou have been dealt: " << endl;
	mPlaya.InitPlayerHand(*mDeck.Deal(), *mDeck.Deal());
	
	cout << "\nThe Dealer is showing: " << endl;
	mDeala.AddCardToDHand(*mDeck.Deal());

	cout << "\nYou currently have: " << mPlaya.GetPlayerHandValue() << endl;

	Check21(mPlaya.GetPlayerHandValue());

	DoubleDownOption = mPlaya.GetPlayerHandValue();

	if (DoubleDownOption == 10 || DoubleDownOption == 11)
	{
		DoubleDownWager = mPlaya.CheckDoubleDownWager();

		if (DoubleDownWager == true)
		{
			DoubleDownOrNah = CheckDoubleDown(DoubleDownOption);

			if (DoubleDownOrNah == true)
			{
				mPlaya.DoubleTheWager();

				mPlaya.AddCardToPHand(*mDeck.Deal());
			}

			else
			{
				Playerbusts = mPlaya.HitStay(mDeck, Playerbusts);
			}
		}

		else
		{
			Playerbusts = mPlaya.HitStay(mDeck, Playerbusts);
		}
	}

	else
	{
		Playerbusts = mPlaya.HitStay(mDeck, Playerbusts);
	}
	
	cout << "You now have a current hand value of: " << mPlaya.GetPlayerHandValue() << endl;

	StartDealerTurn = Playerbusts;

	if (StartDealerTurn == false && EndDealerTurn == false)
	{
		cout << "\nThe dealer is now showing: " << endl;
		mDeala.AddCardToDHand(*mDeck.Deal());

		Check21(mDeala.GetDealerHandValue());
		Dealerbusts = mDeala.DealerPlays21(mDeck, Dealerbusts);

		cout << "\nThe Dealer's hand has a value of: " << mDeala.GetDealerHandValue() << endl;
		
		EndDealerTurn = true;
		StartDealerTurn = true;

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

	//If you're broke or won too much, see ya!
	if (MoneyAtEndOfHand == 0 || MoneyAtEndOfHand >= 50000)
	{
		cout << "\nThanks for playing but come back another day." << endl;
		
		exit = true;
	}

	//Clear both of the hands.
	mPlaya.ClearHand();
	mDeala.DealerClearHand();

	return exit;
}

/****************************************************************************
Purpose: Check if you hit blackjack or nah.

Entry: Int value that represents the hand value.

Exit: Check if player/dealer hit blackjack.
*****************************************************************************/
void Blackjack::Check21(int handvalue)
{
	//WINNER WINNER CHICKEN DINNER
	if (handvalue == 21)
	{
		cout << "You hit BlackJack! Stay your hand." << endl;
	}
}

/****************************************************************************
Purpose: Check if you busted or nah.

Entry: Int value that reprsents the hand value.

Exit: Check if player/dealer busted.
*****************************************************************************/
void Blackjack::BustOrNah(int bustmate)
{
	if (bustmate > 21)
	{
		cout << "Sorry mate, you just busted." << endl;
	}
}

/****************************************************************************
Purpose: Check if you want to double down.

Entry: Int value that represents the hand value.

Exit: Return a bool that represents the user's choice to double down or not.
*****************************************************************************/
bool Blackjack::CheckDoubleDown(int handvalue)
{
	char doubledownchoice = NULL;
	bool doubledownornah(false);

	cout << "Would you like to double down? (Y/N):" << endl;
	cin >> doubledownchoice;

	doubledownchoice = toupper(doubledownchoice);

	cout << endl;

	switch (doubledownchoice)
	{
		case 'Y':
		{
			doubledownornah = true;

			break;
		}

		case 'N':
		{
			break;
		}

		default:
			cout << "Sorry, that was not a valid menu option, please try again.\n" << endl;
	}

	return doubledownornah;
}