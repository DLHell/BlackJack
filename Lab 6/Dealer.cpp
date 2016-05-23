#include "Dealer.h"

/****************************************************************************
Purpose: Default Constructor.

Entry: Nothing.

Exit: A constructor that can be called without any parameters.
*****************************************************************************/
Dealer::Dealer()
{	}

/****************************************************************************
Purpose: Dtor.

Entry: Nothing.

Exit: Invoked when an object is destoryed to free up allocated space.
*****************************************************************************/
Dealer::~Dealer()
{	}

/****************************************************************************
Purpose: Add a Card to the Dealer's Hand.

Entry: a Card.

Exit: A Card is added to the dealer's Hand and the hand value is recalculated.
*****************************************************************************/
void Dealer::AddCardToDHand(Card mdCard)
{
	mDealerHand.AddCardToHand(mdCard);

	mDealerHand.CountHandValue();
}

/****************************************************************************
Purpose: Getter for Dealer's Hand value.

Entry: Nothing.

Exit: Return the value of Dealer's Hand.
*****************************************************************************/
int Dealer::GetDealerHandValue() const
{
	return mDealerHand.GetHandValue();
}

/****************************************************************************
Purpose: Dealer's capabilities.

Entry: Deck and a bool to be able to deal Cards and check if the dealer busts.

Exit: The dealer hits until a hand value of 17 and returns a bool to check if
the dealer has busted or not. Calculates and runs the dealer's portion.
*****************************************************************************/
bool Dealer::DealerPlays21(Deck & mDeck, bool mBusts)
{
	bool dealerbusted(false);
	bool hittill17(false);

	while (GetDealerHandValue() < 21 && hittill17 == false)
	{
		//Should handvalue be < 17 not 21? but then how to check for bust?
		if (GetDealerHandValue() < 17)
		{
			DealerHits(*mDeck.Deal());

			mDealerHand.CountHandValue();
		}

		else //Dealer has 17/18/19/20/21 already
		{
			cout << "Dealer stays with a hand of: " << GetDealerHandValue() << endl;
			
			hittill17 = true;
		}
	}

	if (GetDealerHandValue() == 21)
	{
		cout << "Dealer has 21." << endl;
	}

	else if (GetDealerHandValue() > 21)
	{
		cout << "The Dealer has busted." << endl;

		dealerbusted = true;
	}

	return dealerbusted;
}

/****************************************************************************
Purpose: Dealer hits.

Entry: a Card.

Exit: Call a function that adds a Card to the dealer's Hand.
*****************************************************************************/
void Dealer::DealerHits(Card mCard)
{
	mDealerHand.AddCardToHand(mCard);
}

/****************************************************************************
Purpose: Clearing the Dealer's Hand at the end of the round.

Entry: Nothing.

Exit: Basically call the Dtor of the Hand for the Dealer so if there is another
round played, dealer starts with a fresh hand.
*****************************************************************************/
void Dealer::DealerClearHand()
{
	mDealerHand.~Hand();
}