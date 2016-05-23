/*************************************************************************
* Author:					Daniel Lee
* Date Created:				5/14/16
* Last Modification Date:	5/23/16
* Lab Number:				CST 136
* Filename:					Lab 6.cpp
*
* Overview: This program will play Blackjack and display the game options
* and the game itself. The player will be offered to play a round and then
* dealt two cards to start. The player starts with $1000 and bets at the
* start of every round. If the player wins the round, they are paid back
* their wager and another amount equaling their wager, if they lose, the
* house keeps their bet. The player's goal is the beat the dealer who
* represents the house. There are multiple conditions in winning for the 
* player: 1) The player achieves 21, or Blackjack, and the dealer cannot
* match the hand value. 2) Dealer busts, goes over 21. 3) Player has a
* higher hand value than the dealer when neither has busted. The player is
* able to enjoy playing the game until they wish to stop or their bankroll
* has hit 0 or the player has won too much from the house.
*
* Input: The player's choices.
*
* Output: The program will display the game of Blackjack as it is played.
* Ex:	Welcome to Blackjack!
*		Would you like to play a round? (Y/N)
*		y
*		You currently have: $1000
*		How much would you like to wager: 200
*		SHUFFFLLLINGGGGGGGGGGGGGGG!!!
*		You have been dealt:
*		Eight of Diamonds
*		Ten of Diamonds
*		The Dealer is showing:
*		Five of Hearts
*		You currently have: 18
*		Would you like to hit or stay? (y/n)
*************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include "BlackJack.h"

using std::cout;
using std::endl;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Blackjack game;

	game.MainMenu();

	return 0;
}