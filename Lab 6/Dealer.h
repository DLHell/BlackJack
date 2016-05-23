#ifndef DEALER_H
#define DEALER_H

#include "Hand.h"

class Dealer
{
public:
	Dealer();	//Ctor
	~Dealer();	//Dtor
	bool DealerPlays21(Deck &, bool);	//Main driver for dealer
	void AddCardToDHand(Card);
	int GetDealerHandValue() const;	//Get Dealer's Hand value
	void DealerHits(Card);	//Dealer hits till 17
	void DealerClearHand();	//Clear the hand	

private:
	Hand mDealerHand;	//Dealer's hand
	int mDealerHandValue;	//Dealer's Hand value
};

#endif