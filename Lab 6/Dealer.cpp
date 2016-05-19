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

	//mdCard.Display();
}

int Dealer::GetDealerHandValue() const
{
	return mDealerHandValue;
}