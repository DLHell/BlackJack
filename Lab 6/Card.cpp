#include "Card.h"

/****************************************************************************
Purpose: Default - 2 arg Constructor.

Entry: Nothing.

Exit: A constructor that can be called without any parameters.
*****************************************************************************/
Card::Card(Rank rank, Suit suit) : mRank(rank), mSuit(suit)
{ }

/****************************************************************************
Purpose: Dtor.

Entry: Nothing.

Exit: Invoked when an object is destoryed to free up allocated space.
*****************************************************************************/
Card::~Card()
{
	mRank = ACE;
	mSuit = HEARTS;
}

/****************************************************************************
Purpose: Copy Constructor.

Entry: A copy.

Exit: Copies the rank and suit of the card.
*****************************************************************************/
Card::Card(const Card & copy)
{
	mRank = copy.mRank;
	mSuit = copy.mSuit;
}

/****************************************************************************
Purpose: Display function.

Entry: Nothing.

Exit: Display a card with the number and suit.
*****************************************************************************/
void Card::Display()
{
	const char*rank_txt[] = { "Ace", "Two", "Three", "Four", "Five", "Six", 
		"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	cout << rank_txt[mRank - 1] << " of " << static_cast<char>(mSuit) << endl;
}

/****************************************************************************
Purpose: Rank Setter.

Entry: rank.

Exit: Set mRank to rank.
*****************************************************************************/
void Card::SetRank(Rank rank)
{
	mRank = rank;
}

/****************************************************************************
Purpose: Suit Setter.

Entry: suit.

Exit: Set mSuit to suit.
*****************************************************************************/
void Card::SetSuit(Suit suit)
{
	mSuit = suit;
}

/****************************************************************************
Purpose: Rank Getter.

Entry: Nothing.

Exit: Return mRank.
*****************************************************************************/
Rank Card::GetRank() const
{
	return mRank;
}

/****************************************************************************
Purpose: Suit Getter.

Entry: Nothing.

Exit: Get mSuit.
*****************************************************************************/
Suit Card::GetSuit() const
{
	return mSuit;
}