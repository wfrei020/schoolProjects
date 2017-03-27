#include "Card.h"
/*Gems*/
char gems[] = {'Q','H' ,'O','M','T','R','A','E'};
//Implementation of Quartz class
Quartz::Quartz(){}
//Quartz::~Quartz(){}
int Quartz::getCardsPerCoin(int coins){
	int numberOfCards = 0;
	if(coins = 0){return 0;} // should return some sort of illegal argument
	while(coins > 0){
		int i = 0;
		while(i < 4){
			if(coins <= d_TableForCardToCoins[i].numberOfCoinsNeeded){
				numberOfCards = numberOfCards + d_TableForCardToCoins[i].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[i].numberOfCoinsNeeded;
				if(coins == 0){break;}}
			else if(i = 3){
				numberOfCards = numberOfCards + d_TableForCardToCoins[3].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[3].numberOfCoinsNeeded;
				break;}
			i++;}}
	if(numberOfCards > MaxNumberOfCards){return 0;}//should return a problem saying it is not possible
	return numberOfCards;
	}

string Quartz::getName(){return nameOfCard;}

void Quartz::print(ostream& out)const{out<<"Q"<<" ";}

//Implementation of Hematite class

int Hematite::getCardsPerCoin(int coins){
	int numberOfCards = 0;
	if(coins = 0){return 0;} // should return some sort of illegal argument
	while(coins > 0){
		int i = 0;
		while(i < 4){
			if(coins <= d_TableForCardToCoins[i].numberOfCoinsNeeded){
				numberOfCards = numberOfCards + d_TableForCardToCoins[i].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[i].numberOfCoinsNeeded;
				if(coins == 0){break;}}
			else if(i = 3){
				numberOfCards = numberOfCards + d_TableForCardToCoins[3].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[3].numberOfCoinsNeeded;
				break;}
			i++;}}
	if(numberOfCards > MaxNumberOfCards){return 0;}//should return a problem saying it is not possible
	return numberOfCards;}

string Hematite::getName(){return nameOfCard;}

void Hematite::print(ostream& out)const{out<<"H"<<" ";}//still dont know what this is for

//Implementation of Obsidian class

int Obsidian::getCardsPerCoin(int coins){
	int numberOfCards = 0;
	if(coins = 0){return 0;} // should return some sort of illegal argument
	while(coins > 0){
		int i = 0;
		while(i < 4){
			if(coins <= d_TableForCardToCoins[i].numberOfCoinsNeeded){
				numberOfCards = numberOfCards + d_TableForCardToCoins[i].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[i].numberOfCoinsNeeded;
				if(coins == 0){break;}}
			else if(i = 3){
				numberOfCards = numberOfCards + d_TableForCardToCoins[3].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[3].numberOfCoinsNeeded;
				break;}
			i++;}}
	if(numberOfCards > MaxNumberOfCards){return 0;}//should return a problem saying it is not possible
	return numberOfCards;}

string Obsidian::getName(){return nameOfCard;}

void Obsidian::print(ostream& out)const{out<<"O"<<" ";}//still dont know what this is for

//Implementation of Malachite class

int Malachite::getCardsPerCoin(int coins){
	int numberOfCards = 0;
	if(coins = 0){return 0;} // should return some sort of illegal argument
	while(coins > 0){
		int i = 0;
		while(i < 4){
			if(coins <= d_TableForCardToCoins[i].numberOfCoinsNeeded){
				numberOfCards = numberOfCards + d_TableForCardToCoins[i].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[i].numberOfCoinsNeeded;
				if(coins == 0){break;}}
			else if(i = 3){
				numberOfCards = numberOfCards + d_TableForCardToCoins[3].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[3].numberOfCoinsNeeded;
				break;}
			i++;}}
	if(numberOfCards > MaxNumberOfCards){return 0;}//should return a problem saying it is not possible
	return numberOfCards;}

string Malachite::getName(){return nameOfCard;}

void Malachite::print(ostream& out)const{out<<"M"<<" ";}//still dont know what this is for

//Implementation of Turquoise class

int Turquoise::getCardsPerCoin(int coins){
	int numberOfCards = 0;
	if(coins = 0){return 0;} // should return some sort of illegal argument
	while(coins > 0){
		int i = 0;
		while(i < 4){
			if(coins <= d_TableForCardToCoins[i].numberOfCoinsNeeded){
				numberOfCards = numberOfCards + d_TableForCardToCoins[i].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[i].numberOfCoinsNeeded;
				if(coins == 0){break;}}
			else if(i = 3){
				numberOfCards = numberOfCards + d_TableForCardToCoins[3].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[3].numberOfCoinsNeeded;
				break;}
			i++;}}
	if(numberOfCards > MaxNumberOfCards){return 0;}//should return a problem saying it is not possible
	return numberOfCards;}

string Turquoise::getName(){return nameOfCard;}

void Turquoise::print(ostream& out)const{out<<"T"<<" ";}//still dont know what this is for

//Implementation of Ruby class

int Ruby::getCardsPerCoin(int coins){
	int numberOfCards = 0;
	if(coins = 0){return 0;} // should return some sort of illegal argument
	while(coins > 0){
		int i = 0;
		while(i < 4){
			if(coins <= d_TableForCardToCoins[i].numberOfCoinsNeeded){
				numberOfCards = numberOfCards + d_TableForCardToCoins[i].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[i].numberOfCoinsNeeded;
				if(coins == 0){break;}}
			else if(i = 3){
				numberOfCards = numberOfCards + d_TableForCardToCoins[3].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[3].numberOfCoinsNeeded;
				break;}
			i++;}}
	if(numberOfCards > MaxNumberOfCards){return 0;}//should return a problem saying it is not possible
	return numberOfCards;}

string Ruby::getName(){return nameOfCard;}

void Ruby::print(ostream& out)const{out<<"R"<<" ";}//still dont know what this is for

//Implementation of Amethyst class

int Amethyst::getCardsPerCoin(int coins){
	int numberOfCards = 0;
	if(coins = 0){return 0;} // should return some sort of illegal argument
	while(coins > 0){
		int i = 0;
		while(i < 4){
			if(coins <= d_TableForCardToCoins[i].numberOfCoinsNeeded){
				numberOfCards = numberOfCards + d_TableForCardToCoins[i].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[i].numberOfCoinsNeeded;
				if(coins == 0){break;}}
			else if(i = 3){
				numberOfCards = numberOfCards + d_TableForCardToCoins[3].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[3].numberOfCoinsNeeded;
				break;}
			i++;}}
	if(numberOfCards > MaxNumberOfCards){return 0;}//should return a problem saying it is not possible
	return numberOfCards;}

string Amethyst::getName(){return nameOfCard;}

void Amethyst::print(ostream& out)const{out<<"A"<<" ";}

//Implementation of Emerald class

int Emerald::getCardsPerCoin(int coins){
	int numberOfCards = 0;
	if(coins = 0){return 0;} // should return some sort of illegal argument
	if(coins < 2){return 0;	} //not possible since it need at least 2 or more cards
	while(coins > 0){
		int i = 0;
		while(i < 2){
			if(coins <= d_TableForCardToCoins[i].numberOfCoinsNeeded){
				numberOfCards = numberOfCards + d_TableForCardToCoins[i].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[i].numberOfCoinsNeeded;
				if(coins == 0){break;}}
			else if(i = 1){
				numberOfCards = numberOfCards + d_TableForCardToCoins[1].numberOfCardsNeeded;
				coins = coins -  d_TableForCardToCoins[1].numberOfCoinsNeeded;
				break;}
			i++;}}
	if(numberOfCards > MaxNumberOfCards){return 0;}
	return numberOfCards;}

string Emerald::getName(){return nameOfCard;}

void Emerald::print(ostream& out)const{out<<"E"<<" ";}
