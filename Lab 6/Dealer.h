#ifndef DEALER_H
#define DEALER_H

#include "Hand.h"

class Dealer
{
public:
	Dealer();	//Ctor
	~Dealer();	//Dtor
	void DealerPlays21();	//Main driver for dealer
	void AddCardToDHand(Card);
	//void Bet();	//Bet money
	//void HitStay(Card);	//Make a choice of hit/stay
	//void Deal();	//How do I make this call Deck's deal?
	////void AddCardToPHand(Card);	//Add a card to player's hand
	//void AddMoney();	//Add money at the end of round
	//Bankroll GetBankroll() const;	//Get player's money
	////void Check21();	//Check if blackjack
	int GetDealerHandValue() const;	//Get Dealer's Hand value
	//Hand GetPlayerHand() const;	//Get player's Hand?
	//void InitPlayerHand(Card, Card);	//Passes in two cards
	//void PlayerHit(Card);
	//void PlayerStay();

	//void HitTill17();

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