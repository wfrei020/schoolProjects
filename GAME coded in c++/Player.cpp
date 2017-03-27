#include "Player.h"

//exception structure

struct NotEnoughCoins : public exception {const char * what () const throw () {return "c";}};

//constructors it will create a hand as well;

Player::Player(string& name):playerName(name){playerHand = new Hand();}

//constructor to recontruct a game from a file

Player::Player(std::istream& _is , CardFactory* factory){
	std::string token , typeofChain ;
		_is>>numberOfChains;
		_is >> playerName;
		_is>>token;	
		if(token == "coins"){_is>>numberOfCoins;}
		int i = 0;
		while(i < numberOfChains){
			_is>>typeofChain;
			if(typeofChain == "empty"){break;} //fixed >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			switch(getType(typeofChain)){
					case 0:chains[i] = new Chain<Quartz>(_is, factory);break;
					case 1:chains[i] = new Chain<Hematite>(_is, factory);break;
					case 2:chains[i] = new Chain<Obsidian>(_is, factory);break;
					case 3:chains[i] = new Chain<Malachite>(_is, factory);break;
					case 4:chains[i] = new Chain<Turquoise>(_is, factory);break;
					case 5:chains[i] = new Chain<Ruby>(_is, factory);break;
					case 6:chains[i] = new Chain<Amethyst>(_is, factory);break;
					case 7:chains[i] = new Chain<Emerald>(_is, factory);break;}
			i++;}
		_is >> token;
		if (token == "hand"){
			playerHand = new Hand(_is, factory);}}

//insertion operator to print name, coins and chains (need to check if chains are available)

std::ostream& operator<<(std::ostream& _os, const Player& _player){
	_os << _player.playerName << "\t" <<_player.numberOfCoins <<" coins "<<endl;
	if(_player.chains[0]){
		if(!_player.chains[0]->isEmpty()){	_os<<*_player.chains[0]<<endl;}
		else{_os<<"empty chain"<<endl;	}}
	else{_os<<"empty chain"<<endl;}
	if(_player.chains[1]){
		if(!_player.chains[1]->isEmpty()){
		_os<<*_player.chains[1]<<endl;}
		else{_os<<"empty chain"<<endl;	}}	
	else{_os<<"empty chain"<<endl;}
	if(_player.numberOfChains == 3){
		if(_player.chains[2]){
			if(!_player.chains[2]->isEmpty()){
				_os<<*_player.chains[2]<<endl;}
			else{_os<<"empty chain"<<endl;}}	
		else{_os<<"empty chain"<<endl;}		} 


	return _os;}
	
//print to file according to the way my reconstruction contructors read the data

void Player::printToFile(std::ostream& _os){
	_os<<playerName<<" coins "<<numberOfCoins<<" ";
	if(chains[0]){
		if(!chains[0]->isEmpty()){	
			_os<<*chains[0]<<" end ";}
		else{_os<<" empty ";}}
	else{_os<" empty ";}
	if(chains[1]){
		if(!chains[1]->isEmpty()){	
			_os<<*chains[1]<<" end ";}
		else{_os<<" empty ";}}
	else{_os<" empty ";}
	if(numberOfChains == 3 &&chains[2]){
		if(!chains[2]->isEmpty()){	
			_os<<*chains[2]<<" end ";}
		else{_os<<" empty ";}}
	else{_os<" empty ";}	
	_os<<" hand "<<*playerHand <<" end "<<endl;}

//print the players first or entire hand depending on show

void Player::printHand(std::ostream& _os , bool show){
	if(!show){_os<<playerHand->top()->getName()<<" ";}
	else if(show){_os<<*playerHand<<" ";}
	_os<<"\n";}

//get the players name

string Player::getName(){return playerName;}
int Player::getNumCoins(){return numberOfCoins;}
Player& Player::operator+=(int i){numberOfCoins += i; return *this;}

//get the Max number of chains the players has available empty or full

int Player::getMaxNumChains(){return numberOfChains;}

//get the number of non zero chains

int Player::getNumChains(){
	int i= 0;
	int nonzero = 0;
	while(i < numberOfChains){
		if(chains[i]){
			if(!chains[i]->isEmpty()){nonzero++;}
		}
		i++;}
	return nonzero;}
	
//returns a chain at the number required starting at 1 - max	

Chain_Base& Player::operator[](int i){return *chains[i-1];}

//attempts to buy a third chain, if it can't it will return why

void Player::buyThirdChain(){//buy third chain
if(numberOfCoins > 2){
	numberOfCoins = numberOfCoins -2;
	numberOfChains++;}
else{throw NotEnoughCoins();cout<<"not enoughs coins"<<endl;}}

//return the players hand

Hand& Player::getPlayerHand(){return *playerHand;}

//It will intiate a new chain depending on the the type and which chain_base object to create

void Player::getNewChain(std::string type , int i){
		switch(getType(type)){
			case 0:chains[i] = new Chain<Quartz>(new Quartz());break;
			case 1:chains[i] = new Chain<Hematite>(new Hematite());break;
			case 2:chains[i] = new Chain<Obsidian>(new Obsidian());break;
			case 3:chains[i] = new Chain<Malachite>(new Malachite());break;
			case 4:chains[i] = new Chain<Turquoise>(new Turquoise());break;
			case 5:chains[i] = new Chain<Ruby>(new Ruby());break;
			case 6:chains[i] = new Chain<Amethyst>(new Amethyst());break;
			case 7:chains[i] = new Chain<Emerald>(new Emerald());break;}}

//it wil return the a number correlating to the car type used for the switch statement

int Player::getType(std::string type){
	int i = 0;
	if(type == "Hematite"){i =1;}
	else if(type == "Obsidian"){i = 2;}
	else if(type == "Malachite"){i = 3;}
	else if(type =="Turquoise"){i = 4;}
	else if(type=="Ruby"){i = 5;}
	else if(type=="Amethyst"){i = 6;}
	else if(type=="Emerald"){i = 7;}
	return i;
	}
	
