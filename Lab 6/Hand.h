#ifndef HAND_H
#define HAND_H

#include "Deck.h"

class Hand
{
public:
	Hand();
	~Hand();
	int GetHandValue() const;
	int GetNumOfCardsInHand() const;
	void AddCardToHand(Card);
	void SetHandValue(int);
	
//private:	//This is just for visual appearance for organization
	void CountHandValue();

private:	//data members
	Card * mHand;
	int mHandValue;
	int mNumOfCardsInHand;
};

#endif