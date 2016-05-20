#ifndef BANKROLL_H
#define BANKROLL_H

#include <iostream>

using std::cout;
using std::endl;

class Bankroll
{
public:
	Bankroll();	//Ctor
	~Bankroll();	//Dtor
	void BetMoney(int);	//Bet money/subtract money
	int GetMoney() const;	//Getter for money
	void AddMoney(int);	//Add in money

private:
	int money;
};


#endif