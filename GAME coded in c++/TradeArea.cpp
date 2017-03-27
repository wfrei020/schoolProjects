#include "TradeArea.h"

//constructors

TradeArea::TradeArea(std::istream& _is , CardFactory* factory ){
	std::string tempCard;
	_is >>tempCard;
	if(tempCard == "tradearea"){		
		while(_is >> tempCard){if(tempCard != "end" && tempCard != "No"){tradeArea.push_back(factory->getCard(tempCard));}
	else{break;}}}}

//insertion operator

std::ostream& operator<<(std::ostream& _os, const TradeArea& _tradearea){
	if(!_tradearea.tradeArea.empty()){
			for(auto iter = _tradearea.tradeArea.begin() ; iter  != _tradearea.tradeArea.end();iter++){
				_os<<**iter<<" ";}}
	else{_os<<"No Cards on The table";}
	return _os;}

//add a card To the trade area

TradeArea& TradeArea::operator+= (Card* newCard){
	tradeArea.push_back(newCard);
	return *this;
}

//is a Card legal in the Trade are? (Is there an existing card in the Trade area with similar gemstone

bool TradeArea::legal(Card* card){
	bool found = 0;
	Card* tempCard;
	for(auto iter = tradeArea.begin();iter !=tradeArea.end();++iter){
		tempCard = *iter;
		if(tempCard->getName() == card->getName()){found = true;}}
	return found;}

//remove the card from the trade area

Card* TradeArea::trade(string str){
	Card* take;
	for(auto iter = tradeArea.begin();iter !=tradeArea.end();++iter){
		take = *iter;
		if(take->getName() == str){tradeArea.erase(iter);break;}}
		return take;}
		
//Checks if trade area is empty

bool TradeArea::isEmpty(){return tradeArea.empty();}	
