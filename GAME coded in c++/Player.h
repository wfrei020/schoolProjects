#ifndef _PLAYER_H
#define _PLAYER_H
#include <string>
#include <iostream>
#include "Hand.h"
#include "chain.h"
#include <exception>
//Header files not commented
class Player{
string playerName;	
int numberOfCoins = 0;
int numberOfChains = 2;
Hand* playerHand;


	public:
		Chain_Base* chains[3];
		Player() = default;
		~Player();
		Player(string& name);
		Player(std::istream& _is , CardFactory*);
		friend std::ostream& operator<<(std::ostream&, const Player&);
		void printHand(std::ostream& _os , bool show);
		string getName();
		int getNumCoins();
		Player& operator+=(int);
		int getMaxNumChains();
		int getNumChains();
		Chain_Base& operator[](int i);
		void buyThirdChain();
		
		//helper methods
		
		void printToFile(std::ostream&);
		Hand& getPlayerHand();
		void getNewChain(std::string, int);
		void addToHand(Card* card){*playerHand+=card;}
		int getType(std::string);
		void arrangeChain();
	// meed to implement ostream and istream still
};
 

#endif
