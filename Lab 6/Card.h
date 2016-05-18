#ifndef CARD_H
#define CARD_H

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum Suit { HEARTS = 1, DIAMONDS, CLUBS, SPADES };

class Card
{
public:
	Card(Rank rank = ACE, Suit suit = HEARTS);	//2 Arg Ctor
	~Card();	//Dtor
	Card(const Card & copy);	//Copy Ctor
	void Display();	//Display function
	void SetRank(Rank rank);	//Rank Setter
	void SetSuit(Suit suit);	//Suit Setter
	Rank GetRank() const;	//Rank Getter
	Suit GetSuit() const;	//Suit Getter

private:
	Rank mRank;	//Card Rank
	Suit mSuit;	//Card Suit
};

#endif