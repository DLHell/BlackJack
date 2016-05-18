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

//mPlaya.Bet();
//
////Every day I'm shufflin
//mDeck.Shuffle();

/*for (int i = 0; i < 2; i++)
{
mDeck.Deal().Display();
}*/

/*
Player.deal
Dealer.deal?
*/
//cout << "\nYou have been dealt: " << endl;
//mPlaya.AddCardToPHand(mDeck.Deal());	//Display card
//mPlaya.AddCardToPHand(mDeck.Deal());	//Display card
//
//cout << "\nThe Dealer is showing: " << endl;
//mDeala.AddCardToDHand(mDeck.Deal());
/*
playa.AddCardToPHand();	//Display card
deala.AddCardToDHand();	//Display card
playa.AddCardToPHand();	//Display card
deala.AddCardToDHand();	//Do not display card
*/

//How do I get the Ace to be 1 or 11?
//How do I get the program to realize the values of the cards?

/*
PlayerHandValue = card1value + card2value;
cout << "You currently have: " << PlayerHandValue;

Check21();

HitStay();

BustOrNah();	//Is this a Blackjack function?
//Check if PlayerHandValue > 21;

*Flip* Dealer's hidden card.
DealerHandValue = dcard1value + dcard2value;
Check here to see if Dealer is below 17. If so, hit until 17.
Check21();

BustOrNah();	//Is this a Blackjack function?
//Check if DealerHandValue > 21;

//Can you make BustOrNah and Check21 the same function?

if (DealerHandValue < PlayerHandValue)
{
cout << "You've won the round! Enjoy your winnings." << endl;
AddMoney();	//double the wager amount here
end round. (Do you have to destory deck here?)
}

else if (DealerHandValue == PlayerHandValue)
{
cout << "It's a draw!" << endl;
AddMoney(wager);	//Give back wager

else if (DealerHandValue > PlayerHandValue)
{
cout << "Sorry, the dealer has won" << endl;
take money here.	//So do nothing?
end round. (Do you have to destory deck here?)
}
*/


/*if (money == 0 || money >= 50000)
{
cout << "Thanks for playing but come back another day." << endl;
exit = true;
}*/

//else

//GoAgain(exit);	//FIRST PRIORITY