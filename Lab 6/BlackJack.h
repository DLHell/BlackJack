#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Dealer.h"

class Blackjack
{
public:
	Blackjack();	//Ctor
	~Blackjack();	//Dtor
	bool Play21();	//Main Driver
	void MainMenu();	//Called at the very beginning of the program
	void Check21(int);	//Check if blackjack
	void BustOrNah(int);	//Check if bust or nah
	bool CheckDoubleDown(int);	//Check if player wants to double down

private:
	Player mPlaya;	//The Player
	Dealer mDeala;	//The Dealer
	Deck mDeck;	//Deck
};

#endif