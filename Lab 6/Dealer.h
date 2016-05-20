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
	//void HitStay(Card);	//Make a choice of hit/stay
	//void Deal();	//How do I make this call Deck's deal?
	////void AddCardToPHand(Card);	//Add a card to player's hand
	////void Check21();	//Check if blackjack
	int GetDealerHandValue() const;	//Get Dealer's Hand value
	//Hand GetPlayerHand() const;	//Get player's Hand?
	//void InitPlayerHand(Card, Card);	//Passes in two cards
	void DealerHits(Card);	//void HitTill17();
	void DealerClearHand();	//Clear the hand
	

private:
	Hand mDealerHand;	//Dealer's hand
	int mDealerHandValue;	//Dealer's Hand value

};
/*
has unlimited bankroll
can hit or stay
must hit 17/18/19/20/21 and then stay.
can bust

*/

#endif