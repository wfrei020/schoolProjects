#include "CardFactory.h"

//private constructor which generates the cards

CardFactory::CardFactory(){
		int i = 20;
		while(i > 0){
			allCards.push_back(new Quartz);
			if(i <=18){allCards.push_back(new Hematite );}
			if(i <= 16){allCards.push_back(new Obsidian);}
			if(i <= 14){allCards.push_back(new Malachite);}
			if(i <= 12){allCards.push_back(new Turquoise);}
			if(i <= 10){allCards.push_back(new Ruby);}
			if(i <= 8){allCards.push_back(new Amethyst);}
			if(i <= 6){allCards.push_back(new Emerald);}	
			i--;}}

CardFactory* CardFactory::getFactory(){ static CardFactory* instance = new CardFactory(); return instance;}

//get a Shuffled vector of the cards in order to create the deck
 
std::vector<Card*> CardFactory::getDeck(){
 			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			std::shuffle (allCards.begin(), allCards.end(), std::default_random_engine(seed));
 			return allCards;}
 			
//Used to reconstruct a Deck from a file instead of looking through the cards created
 
 Card* CardFactory::getCard(std::string type){
 	Card* card;
 	if(type == "Quartz" || type == "Q"){card = new Quartz();}
	else if(type == "Hematite" || type == "H"){card = new Hematite();}
 	else if(type == "Obsidian" || type == "O"){card = new Obsidian();}
 	else if(type == "Malachite" || type == "M"){card = new Malachite();}
 	else if(type == "Turquoise" || type=="T"){card = new Turquoise();}	
	else if(type == "Ruby" || type== "R"){card = new Ruby();}
 	else if(type == "Amethyst"|| type =="A"){card = new Amethyst();}
 	else if(type == "Emerald"|| type == "E"){card = new Emerald();}	 
 	return card;}
