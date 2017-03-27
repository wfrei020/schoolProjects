#ifndef _CARDFACTORY_H
#define _CARDFACTORY_H
#include <algorithm>
#include <vector>
#include "Card.h"
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
//Header files not commented
class CardFactory{
		std::vector<Card*> allCards;
		//making the constructor private (Singleton Pattern)
		CardFactory();	
        CardFactory(CardFactory& other) ;
        CardFactory& operator=(CardFactory& other) ;
	public :
		static CardFactory* getFactory();
		std::vector<Card*> getDeck();
		Card* getCard(std::string);	
};

#endif
