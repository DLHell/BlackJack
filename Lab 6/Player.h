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
	bool HitStay(Deck &, bool);	//Make a choice of hit/stay
	//void Deal();	//How do I make this call Deck's deal?
	void AddCardToPHand(Card);	//Add a card to player's hand
	void AddMoney();	//Add money at the end of round
	Bankroll GetBankroll() const;	//Get player's money
	int GetPlayerHandValue() const;	//Get Hand's value
	Hand GetPlayerHand() const;	//Get player's Hand?
	void InitPlayerHand(Card, Card);	//Passes in two cards
	void PlayerHit(Card);	//Player hits
	//void PlayerStay();	//Player stays
	void ResetHandValue();	//Reset the hand value
	void ClearHand();	//Clear the hand
	int GetMoneyAtEndOfHand();	//Get bankroll at the end of round
	bool CheckDoubleDownWager();	//Can you double down?
	void DoubleTheWager();	//Double the wager

private:
	Bankroll mBankroll;	//Player's money
	Hand mPlayerHand;	//Player's hand
	int mWager;	//Player's wager
};



#endif


/*
a player has a hand
can bet.
can hit.
player starts off with 1 grand.

*/