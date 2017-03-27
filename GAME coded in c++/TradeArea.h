#ifndef _TRADEAREA_H
#define _TRADEAREA_H

#include <iostream>
#include <list>
#include "Card.h"
#include "CardFactory.h"
//Header files not commented

class TradeArea{
	

	
	public:
		std::list<Card*> tradeArea;
		TradeArea() = default;
		TradeArea(std::istream& , CardFactory*);
		friend std::ostream& operator<<(std::ostream& _os,const TradeArea& _tradearea );
		TradeArea& operator+=(Card*);
		bool legal(Card*);
		Card* trade(string);
		int numCards();
		bool isEmpty();
 		
	
};

#endif
