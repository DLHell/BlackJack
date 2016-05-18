/*****************************************************************
*					Random Class
*  Filename:  Random.h
*  Feel free to use your lab - or develop your own or use another one
******************************************************************/
#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>	//c standard library
#include <ctime>	//c time directory
#include <stdlib.h>	//standary library for c++

class Random
{
public:
	Random()
	{ // Seed for random-number generation 
		srand(static_cast<unsigned> (time(0)));
	}

	// rand returns a pseudorandom number, as described above. 
	// The rand function returns a pseudorandom integer in the 
	// range 0 to RAND_MAX. Use srand function to seed the 
	// pseudorandom-number generator before calling rand. BLAH BLAH BLAH ...
	unsigned GetRandom(int n) const { return rand() % n; }
};

#endif