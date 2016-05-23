#include "Hand.h"

/****************************************************************************
Purpose: Default Constructor.

Entry: Nothing.

Exit: A constructor that can be called without any parameters.
*****************************************************************************/
Hand::Hand() : mHand(nullptr), mHandValue(0), mNumOfCardsInHand(0)
{	}

/****************************************************************************
Purpose: Dtor.

Entry: Nothing.

Exit: Invoked when an object is destoryed to free up allocated space.
*****************************************************************************/
Hand::~Hand()
{
	delete[] mHand;
	mHand = nullptr;
	mHandValue = 0;
	mNumOfCardsInHand = 0;
}

/****************************************************************************
Purpose: Getter for Hand Value.

Entry: Nothing.

Exit: return mHandValue.
*****************************************************************************/
int Hand::GetHandValue() const
{
	return mHandValue;
}

/****************************************************************************
Purpose: Getter for number of cards in the hand.

Entry: Nothing.

Exit: return mNumOfCardsInHand.
*****************************************************************************/
int Hand::GetNumOfCardsInHand() const
{
	return mNumOfCardsInHand;
}

/****************************************************************************
Purpose: Allocate space for a Card.

Entry: A Card.

Exit: Space is allocated for a new Card and it is displayed. Also increments
mNumOfCardsInHand.
*****************************************************************************/
void Hand::AddCardToHand(Card mCard)
{
	Card * tempCard = new Card[mNumOfCardsInHand + 1];

	for (int i = 0; i < mNumOfCardsInHand; i++)
	{
		tempCard[i] = mHand[i];
	}

	tempCard[mNumOfCardsInHand] = mCard;

	if (mNumOfCardsInHand != 0)
	{
		delete[] mHand;
	}

	mHand = tempCard;

	mCard.Display();

	mNumOfCardsInHand++;
}

/****************************************************************************
Purpose: Setter for Hand Value.

Entry: Int value that Hand Value is to be set to.

Exit: mHandValue = the passed in integer.
*****************************************************************************/
void Hand::SetHandValue(int num)
{
	mHandValue = num;
}

/****************************************************************************
Purpose: Count the value of the hand.

Entry: Nothing.

Exit: Calculates the value of the hand depending on the cards in the hand.
*****************************************************************************/
void Hand::CountHandValue()
{
	bool IfAceFound(false);
	int CardValue = 0;
	bool Added10Already(false);

	SetHandValue(0);

	for (int i = 0; i < mNumOfCardsInHand; i++)
	{
		//put in the value of the rank into an int CardValue
		CardValue = static_cast<int>(mHand[i].GetRank());
		
		if (CardValue >= 10)
		{
			CardValue = 10;
		}

		else if (CardValue >= 2 && CardValue < 10)
		{
			CardValue = CardValue;
		}

		else if (CardValue == 1)
		{
			IfAceFound = true;
		}

		if (IfAceFound == true)
		{
			mHandValue += CardValue;

			if (mHandValue + 10 <= 21)
			{
				mHandValue += 10;

				Added10Already = true;
			}

			else if (mHandValue > 21 && Added10Already == true)
			{
				mHandValue -= 10;

				Added10Already = false;
			}
		}

		else
			mHandValue += CardValue;
	}
}