#include "Hand.h"

Hand::Hand()
{

}

Hand::~Hand()
{

}

int Hand::GetHandValue() const
{
//	CountHandValue();

	return mHandValue;
}

void Hand::CountHandValue()
{
	bool IfAceFound(false);
	//int tempHandValue = 0;
	int CardValue = 0;

	for (int i = 0; i < mNumOfCardsInHand; i++)
	{
		CardValue = static_cast<int>(mHand[i]->GetRank());
		
		if (CardValue >= 10)
		{
			CardValue = 10;
		}

		if (CardValue == 1)
		{
			IfAceFound = true;
		}

		//BestHandPossible
		if (IfAceFound == true)
		{
			if (CardValue  )
		}



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