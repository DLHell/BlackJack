#ifndef BANKROLL_H
#define BANKROLL_H

#include <iostream>

using std::cout;
using std::endl;

class Bankroll
{
public:
	Bankroll();
	~Bankroll();
	void BetMoney(int);
	int GetMoney() const;
	void AddMoney();

private:
	int money;
};


#endif