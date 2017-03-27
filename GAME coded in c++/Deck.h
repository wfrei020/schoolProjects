#ifndef _DECK_H
#define _DECK_H

#include <vector>
#include <iostream>
#include "Card.h"
#include <string>
#include "CardFactory.h"
//Header files not commented

class Deck{
	std::vector<Card*> deck;
public:
	Deck() = default;
	Deck(std::istream& , CardFactory*);
	Deck(std::vector<Card*> newDeck);
	Card* draw();	
 	friend std::ostream& operator<<(std::ostream& _os , const Deck& _deck );
	bool isEmpty();
};

#endif
