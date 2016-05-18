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
	void Play21();	//Main Driver
	bool GoAgain(bool &);	//Ask for another round
	void Prompt();	//Display of GoAgain
	void MainMenu();	//Called at the very beginning of the program
	void Check21();	//Check if blackjack

private:
	Player mPlaya;
	Dealer mDeala;
	Deck mDeck;

};

#endif

/*
this should be the main driver or the game itself
*/