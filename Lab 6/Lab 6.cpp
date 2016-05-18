#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <iostream>
//#include "Deck.h"
#include "BlackJack.h"

using std::cout;
using std::endl;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	/****** Pseudo Code thought process so far: ******
	WINNER WINNER CHICKEN DINNER, LET'S GO

	Entire thing under a do while loop?
	Give player option to leave, so 2 part menu - 1. play, 2. exit


	Place the bets. (Make sure player can't bet over their bankroll or in decimals)
	Player starts off with a cool grand.

	deck.Shuffle();
	Player.DrawHand()
	Player's draw hand = 2 cards show.
	Dealer's draw hand = 1 card show, 1 card hidden. //Ask aaron for an idea on how to hide a card.
	Maybe deal 2 but display only 1?

	Player sees their hand and dealer's face up card.
	Player is given two options:
	1. Hit
	2. Stay

	Hit:
	Dealer deals a card to Player's hand. Display the card

	Stay:	
	Dealer must draw until he has 17 or more. Must hit until at least 17. (What if dealer wants to hit?)
	(Dealer cannot hit once he has reached 17, so on a hand of 17/18/19/20, he must stand (21 is obvious))

	If either hands has 21 (Ace + 10 value card(10/J/Q/K) with the first two cards of the hand then BlackJack.

	What happens if Dealer and Player match in value? (20-20)
	Return the bet to the player.

	What about Aces? (Can be a 1 or 11)
	What happens if by some dumb luck, you pull more than one Ace into your hand?

	In case game continues after all 52 cards have been dealt, how do you go on?
	Reshuffle? But what you run out of cards in the middle of a hand?
	And so if reshuffling happens, is it possible to get a repeat card that's on the table?

	Player has the option to exit after every round/hand has been played.

	End game:
	1. Player is broke. SEE YA NERD.
	2. Player has accumulated 50000. (Broke the bank) Tell them they have been politely asked to leave the casino.
	if (PlayerMoney == 0 | PlayerMoney >= 50000)
	I can use a bool StopPlaying = false and so if player chooses to exit or meets either of the money conditions.
	StopPlaying = true.

	*******/

	Blackjack game;

	game.MainMenu();

	return 0;
}