#include "Hand.h"

Hand::Hand() : mHandValue(0), mNumOfCardsInHand(0)
{

}

Hand::~Hand()
{

}

int Hand::GetHandValue() const
{
	//mHandValue = CountHandValue();
	//CountHandValue();

	return mHandValue;
}

void Hand::CountHandValue()
{
	bool IfAceFound(false);
	int CardValue = 0;
	mNumOfCardsInHand++;

	for (int i = 0; i < mNumOfCardsInHand; i++)
	{
		CardValue = static_cast<int>(mHand[i]->GetRank());
		
		if (CardValue >= 10)
		{
			CardValue = 10;
		}

		else if (2 <= CardValue < 10)
		{
			CardValue = CardValue;
		}

		else if (CardValue == 1)
		{
			IfAceFound = true;
		}

		mHandValue += CardValue;
		//BestHandPossible
		/*if (IfAceFound == true)
		{
			if (CardValue + 10 <= 21 )
			{
				CardValue += 10;
			}
			else
				//Is there anything even needed here?
		}*/



		/*else if (2 <= CardValue < 10)
		{
			CardValue = CardValue;
		}*/
		/*
		

		else

		BestHandPossible <- check if you can add 10 to hand without going over <= 21;
		If you have an ace

		*/
		/*if (mHand[i]->GetRank() == ACE)
		{
			IfAceFound = true;
		}*/
		//tempHandValue += 1;
	
	}

}