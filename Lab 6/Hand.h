#ifndef HAND_H
#define HAND_H

#include "Deck.h"
#include "Card.h"

class Hand
{
public:
	Hand();
	~Hand();
	int GetHandValue() const;
	
private:	//This is just for visual appearance for organization
	void CountHandValue();

private:	//data members
	Card * mHand[11];
	int mHandValue;
	int mNumOfCardsInHand;
};


#endif

/*
So hand should basically be an array that can be increased based on hit/stay choice
array of Cards of pointer to array of cards
starts off with 2.


*/