#ifndef DEALER_H
#define DEALER_H

#include "Hand.h"

class Dealer
{
public:
	Dealer();
	~Dealer();
	void AddCardToDHand(Card);
	//HitTill17();

private:
	Hand * mDealerHand;

};
/*
has unlimited bankroll
can hit or stay
must hit 17/18/19/20/21 and then stay.
can bust

*/

#endif