#include "DiscardPile.h"

//Constructor from a file

DiscardPile::DiscardPile(std::istream& _is , CardFactory* factory){	
	string tempCard;
	_is >>tempCard;
	if(tempCard == "discard"){	
		while(	_is>>tempCard){
			if(tempCard != "end" && tempCard != "Empty"){discardpile.push_back(factory->getCard(tempCard));}
			else{break;}}}}

//adds a new card to the discard pile

DiscardPile& DiscardPile::operator+=(Card* newDisCard){
	discardpile.push_back(newDisCard);
	return *this;
}

//checks if discardpile is empty

bool DiscardPile::discardEmpty(){return discardpile.empty();}

//Pick up the top card of the discard pile and removes from the vector

Card* DiscardPile::pickUp(){
	Card* temp = discardpile.back();
	discardpile.pop_back();
	return temp;}

//shows the top card of the discard pile
	
Card* DiscardPile::top(){return discardpile.back();}

//prints the discard file in order to save in a file

void DiscardPile::print(std::ostream& _os){for(auto iter = discardpile.begin() ; iter != discardpile.end() ; iter++){
_os << **iter <<" ";}}

//insertion operator to print top most card, need to check if it is empty or it will cause runtime error

std::ostream& operator<<(std::ostream& _os, const DiscardPile& _discardpile){
	if(!_discardpile.discardpile.empty()){
	_os << *(_discardpile.discardpile.back() )<<endl;}
	else{_os<<"empty";}
	return _os;}



