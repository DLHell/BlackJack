#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Blackjack
{
public:
	Blackjack();	//Ctor
	~Blackjack();	//Dtor
	bool Play21();	//Main Driver
	void Prompt();	//Display of GoAgain
	void MainMenu();	//Called at the very beginning of the program
	void Check21(int);	//Check if blackjack
	void BustOrNah(int);	//Check if bust or nah

private:
	Player mPlaya;
	Dealer mDeala;
	Deck mDeck;

};

#endif