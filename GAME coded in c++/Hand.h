#ifndef _HAND_H
#define _HAND_H
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardFactory.h"
//Header files not commented

class Hand{
	
	std::vector<Card*>  hand;
	
	public:
		Hand()= default;
		Hand(std::istream&, CardFactory*);
		friend std::ostream& operator<<(std::ostream& _os, const Hand& _hand);	
		Hand& operator+=(Card*);
		Card* play();
		Card* top();
		Card* operator[](int);
		int sizeOf();	
};

#endif
