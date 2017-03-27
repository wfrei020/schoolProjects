#ifndef _DISCARDPILE_H
#define _DISCARDPILE_H
#include "Card.h"
#include <vector>
#include <iostream>
#include "CardFactory.h"
//Header files not commented

class DiscardPile{

std::vector<Card*> discardpile;
public:
	DiscardPile() =default;
	~DiscardPile();
	DiscardPile(std::istream&, CardFactory*);
	DiscardPile& operator+=(Card*);
	Card* pickUp();
	Card* top();
	void print(std::ostream&);
	bool discardEmpty();
	friend std::ostream& operator<<(std::ostream& _os , const DiscardPile& _discardpile );
	
};

#endif
