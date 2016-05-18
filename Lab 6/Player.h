#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Bankroll.h"

class Player
{
public:
	Player();	//Ctor
	~Player();	//Dtor
	void Bet();	//Bet money
	void HitStay();	//Make a choice of hit/stay
	void Deal();	//How do I make this call Deck's deal?
	void AddCardToPHand(Card);	//Add a card to player's hand
	void AddMoney();	//Add money at the end of round
	Bankroll GetBankroll() const;	//Get player's money
	//void Check21();	//Check if blackjack
	int GetHandValue() const;	//Get Hand's value

private:
	Bankroll mBankroll;	//Player's money
	Hand mPlayerHand;	//Player's hand

};



#endif


/*
a player has a hand
can bet.
can hit.
player starts off with 1 grand.

*/