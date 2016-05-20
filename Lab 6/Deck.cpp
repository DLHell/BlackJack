#include "Deck.h"

int Deck::DeckCount = 0;

/****************************************************************************
Purpose: Default Constructor.

Entry: Nothing.

Exit: A constructor that can be called without any parameters. Cards are now
created with a rank and a suit.
*****************************************************************************/
Deck::Deck() : mCurrentCard(0)
{
	for (int suit = 0; suit < 4; suit++)
	{
		for (int rank = 0; rank < 13; rank++)
		{
			//mDeck[suit * 13 + rank] = new Card(static_cast<Rank>(rank + 1), static_cast<Suit>(suit + 1));
			mDeck[suit * 13 + rank] = new Card(static_cast<Rank>(rank + 1), static_cast<Suit>(suit + 3));
		}
	}
}

/****************************************************************************
Purpose: Dtor.

Entry: Nothing.

Exit: Delete each card pointer of the deck (cards).
*****************************************************************************/
Deck::~Deck()
{
	for (int i = 0; i < 52; i++)
	{
		delete mDeck[i];
	}
}

/****************************************************************************
Purpose: Shuffle the deck.

Entry: Nothing.

Exit: Shuffle through the deck of 52 cards randomly.
*****************************************************************************/
void Deck::Shuffle()
{
	Card *temp = nullptr;
	int number = 0;
	
	Random rand;
	srand(static_cast<unsigned>(time(0)));

	for (int cur = 0; cur < 52; cur++)
	{
		number = rand.GetRandom(52);
		temp = mDeck[cur];
		mDeck[cur] = mDeck[number];
		mDeck[number] = temp;
	}

	cout << "SHUFFFLLLINGGGGGGGGGGGGGGGG!!!" << endl;

	mCurrentCard = 0;
}

/****************************************************************************
Purpose: Deal the cards.

Entry: Nothing.

Exit: Increment count and return a card from the array of cards.
*****************************************************************************/
Card * Deck::Deal()
{
	Deck::DeckCount++;
	
	if (mCurrentCard + 1 > 52)
	{
		Shuffle();
	}
	//return mCurrentCard > 51 ? *mDeck[51] : *mDeck[mCurrentCard++];
	return mDeck[mCurrentCard++];
}

/****************************************************************************
Purpose: Display the number of cards already dealt.

Entry: Nothing.

Exit: The count of dealt cards at the time of the function call.
*****************************************************************************/
//void Deck::DisplayCount()
//{
//	cout << "This is the deck count: " << DeckCount << endl;
//}