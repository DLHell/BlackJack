#include "Dealer.h"

Dealer::Dealer()
{

}

Dealer::~Dealer()
{

}

void Dealer::AddCardToDHand(Card mdCard)
{
	mDealerHand.AddCardToHand(mdCard);

	mDealerHand.CountHandValue();
}

int Dealer::GetDealerHandValue() const
{
	return mDealerHandValue;
}

bool Dealer::DealerPlays21(Deck & mDeck, bool mBusts)
{
	bool dealerbusted(false);

	while (GetDealerHandValue() < 21 && dealerbusted == false)
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

void Dealer::DealerHits(Card mCard)
{
	mDealerHand.AddCardToHand(mCard);
}