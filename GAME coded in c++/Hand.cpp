#include "Hand.h"

//constructor
Hand::Hand(std::istream& _is , CardFactory* factory){		
	string tempCard;
	while(_is>>tempCard){
		if(tempCard != "end" && tempCard != "empty"){hand.push_back(factory->getCard(tempCard));}
		else{break;}}}

//insertion operator

std::ostream& operator<<(std::ostream& _os, const Hand& _hand){
	if(!_hand.hand.empty()){	for(auto iter=_hand.hand.begin(); iter != _hand.hand.end() ; iter++){_os << **iter<<" ";}}
	else{" empty ";}
	return _os;}

//size of hand

int Hand::sizeOf(){return hand.size();}

//Play top most card and remove
Card* Hand::play(){
	Card* temp = hand.front();
	hand.begin() =	hand.erase(hand.begin());
	return temp;}

//get the top card but do not remove

Card* Hand::top(){return hand.front();}

//access any card in the hand and remove it, need to find out destructor

Card* Hand::operator[](int index){
	index--;
	Card* temp = *(hand.begin()+index);
	hand.begin()+index = hand.erase(hand.begin()+index);
	return temp;}

//add a card to the hand

Hand& Hand::operator+=(Card* card){ 
	hand.push_back(card);
	return *this;}
