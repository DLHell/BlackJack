#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"
#include "Random.h"

class Deck
{
public:
	Deck();	//Default Ctor
	~Deck();	//Default Dtor
	void Shuffle();	//Shuffle the deck
	Card * Deal();	//Deal the deck
	//static void DisplayCount();	//Display the count of cards dealt
	static int DeckCount;	//Is it ok here?

private:
	Card * mDeck[52];	//Array of 52 Card pointers
	int mCurrentCard;	//Where you are in the deck
};

#endif