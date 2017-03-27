#ifndef _CARD_H
#define _CARD_H
#include <string>
#include <array>
#include <iostream>

/*
 *
 */
using namespace std;
//Header files not commented
//--------------------------------------------------------------------------------------------------------------
//ase class Card : all functions are virtual...
//--------------------------------------------------------------------------------------------------------------	
class Card{
	public:
		virtual int getCardsPerCoin(int coins) = 0;
		virtual std::string getName() = 0;
		virtual void print(ostream& out) const=0;
};
inline std::ostream& operator<<(std::ostream& _os, const Card& card){
	card.print(_os);
	return _os;
}
//--------------------------------------------------------------------------------------------------------------
//structure used to allocate number of card neccessary for amount of coins and a Gems array with initial letters
//--------------------------------------------------------------------------------------------------------------
struct TableForCardToCoins{
	int numberOfCardsNeeded;
	int numberOfCoinsNeeded;
};


//--------------------------------------------------------------------------------------------------------------
//class Quartz
//--------------------------------------------------------------------------------------------------------------
class Quartz: public Card{

	int MaxNumberOfCards = 20;
	string nameOfCard = "Quartz";
	array<TableForCardToCoins, 4> d_TableForCardToCoins{{   TableForCardToCoins{4,1} , TableForCardToCoins{6,2} , 
																		TableForCardToCoins{8,3} , TableForCardToCoins{10,4} }};
	public:
		Quartz();
		~Quartz();
		int getCardsPerCoin(int coins);
		string getName();
		void print(ostream& out) const;
};
//--------------------------------------------------------------------------------------------------------------
//class Hematite
//--------------------------------------------------------------------------------------------------------------
class Hematite: public Card{
	int MaxNumberOfCards = 18;
	string nameOfCard = "Hematite";
	array<TableForCardToCoins, 4> d_TableForCardToCoins{{   TableForCardToCoins{3,1} , TableForCardToCoins{6,2} , 
																		TableForCardToCoins{8,3} , TableForCardToCoins{9,4} }};
	
	public:
		Hematite() = default;
		~Hematite();
		int getCardsPerCoin(int coins);
		string getName();
		void print(ostream& out)const;
};
//--------------------------------------------------------------------------------------------------------------
//class Obsidian
//--------------------------------------------------------------------------------------------------------------
class Obsidian: public Card{
	int MaxNumberOfCards = 16;
	string nameOfCard = "Obsidian";
	array<TableForCardToCoins, 4> d_TableForCardToCoins{{   TableForCardToCoins{3,1} , TableForCardToCoins{5,2} , 
																			TableForCardToCoins{7,3} , TableForCardToCoins{8,4} }};
	
	public:
		Obsidian() = default;
		~Obsidian();
		int getCardsPerCoin(int coins);
		string getName();
		void print(ostream& out)const;
};
//--------------------------------------------------------------------------------------------------------------
//class Malachite
//--------------------------------------------------------------------------------------------------------------
class Malachite: public Card{
	int MaxNumberOfCards = 14;
	string nameOfCard = "Malachite";
	array<TableForCardToCoins, 4> d_TableForCardToCoins{{   TableForCardToCoins{3,1} , TableForCardToCoins{5,2} , 
																		TableForCardToCoins{6,3} , TableForCardToCoins{7,4} }};
	
	public:
		Malachite() = default;
		~Malachite();
		int getCardsPerCoin(int coins);
		string getName();
		void print(ostream& out)const;
};
//--------------------------------------------------------------------------------------------------------------
//class Turquoise
//--------------------------------------------------------------------------------------------------------------
class Turquoise: public Card{
	int MaxNumberOfCards = 12;
	string nameOfCard = "Turquoise";
	array<TableForCardToCoins, 4> d_TableForCardToCoins{{   TableForCardToCoins{2,1} , TableForCardToCoins{4,2} ,
																		 TableForCardToCoins{6,3} , TableForCardToCoins{7,4} }};
	
	public:
		Turquoise() = default;
		~Turquoise();
		int getCardsPerCoin(int coins);
		string getName();
		void print(ostream& out)const;
};
//--------------------------------------------------------------------------------------------------------------
//class Ruby
//--------------------------------------------------------------------------------------------------------------
class Ruby: public Card{
	int MaxNumberOfCards = 10;
	string nameOfCard = "Ruby";
	array<TableForCardToCoins, 4> d_TableForCardToCoins{{   TableForCardToCoins{2,1} , TableForCardToCoins{4,2} ,
																		 TableForCardToCoins{5,3} , TableForCardToCoins{6,4} }};
	
	public:
		Ruby() = default;
		~Ruby();
		int getCardsPerCoin(int coins);
		string getName();
		void print(ostream& out)const;
};
//--------------------------------------------------------------------------------------------------------------
//class Amethyst
//--------------------------------------------------------------------------------------------------------------
class Amethyst: public Card{
	int MaxNumberOfCards = 8;
	string nameOfCard = "Amethyst";
	array<TableForCardToCoins, 4> d_TableForCardToCoins{{   TableForCardToCoins{2,1} , TableForCardToCoins{3,2} ,
																		 TableForCardToCoins{4,3} , TableForCardToCoins{5,4} }};
	
	public:
		Amethyst() = default;
		~Amethyst();
		int getCardsPerCoin(int coins);
		string getName();
		void print(ostream& out)const;
};
//--------------------------------------------------------------------------------------------------------------
//class Emerald
//--------------------------------------------------------------------------------------------------------------
class Emerald: public Card{
	int MaxNumberOfCards = 6;
	string nameOfCard = "Emerald";
	array<TableForCardToCoins, 2> d_TableForCardToCoins{{ TableForCardToCoins{2,2} ,
																		 TableForCardToCoins{3,3} }};
	
	public:
		Emerald() = default;
		~Emerald();
		int getCardsPerCoin(int coins);
		string getName();
		void print(ostream& out)const;
};


#endif

