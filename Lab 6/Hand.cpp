#include "Hand.h"

Hand::Hand() : mHand(nullptr), mHandValue(0), mNumOfCardsInHand(0)
{
	
}

Hand::~Hand()
{
	delete[] mHand;
	mHand = nullptr;
	mHandValue = 0;
	mNumOfCardsInHand = 0;
}

int Hand::GetHandValue() const
{
	return mHandValue;
}

int Hand::GetNumOfCardsInHand() const
{
	return mNumOfCardsInHand;
}

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
	//for (int x = 0; )

	mHand = tempCard;

	mCard.Display();

	mNumOfCardsInHand++;
}

void Hand::SetHandValue(int num)
{
	mHandValue = num;
	//mHandValue = 0;
}

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