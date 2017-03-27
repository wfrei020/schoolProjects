#include "Deck.h"

//constructors

Deck::Deck(std::vector<Card*> newDeck):deck(newDeck){}
Deck::Deck(std::istream& _is , CardFactory* factory){	
	std::string tempCard;
	_is >>tempCard;
	if(tempCard == "deck"){
		while(	_is>>tempCard){
			if(tempCard != "end" && tempCard != "empty"){deck.push_back(factory->getCard(tempCard));}
			else{break;}}}}
			
//draw a card from the deck

Card* Deck::draw(){
	Card* temp = deck.back();
	deck.pop_back();
	return temp;}
	
//checks if the deck is empty

bool Deck::isEmpty(){return deck.empty();}

//insertion operator

std::ostream& operator<<(std::ostream& _os , const Deck& _deck){
	if(!_deck.deck.empty()){for(auto iter = _deck.deck.begin() ; iter != _deck.deck.end() ; iter++){_os<<**iter<<" ";}}
	else{_os<<"empty";}
	return _os;}
