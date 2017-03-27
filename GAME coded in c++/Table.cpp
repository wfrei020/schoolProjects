#include "Table.h"
#include <string>
#include <fstream>
#include <sstream>
using std::endl;

//constructors

Table::Table(std::string d_player1,std::string d_player2, CardFactory* factory){
	players[0] = new Player(d_player1);
	players[1] = new Player(d_player2);
	deck =*( new Deck(factory->getDeck()));
	discardpile = new DiscardPile();
	tradearea = new TradeArea();	}

//reconstruction of game , it gets a new line for players, tradearea,discardpile and deck
		
Table::Table(std::istream& _is , CardFactory* factory){
	std::string line, token;
	getline(_is,line);istringstream streamline(line);streamline >> token;if(token == "player1"){players[0] = new Player(streamline , factory);}
	getline(_is,line);istringstream streamline2(line);streamline2 >> token;if(token == "player2"){players[1] = new Player(streamline2 , factory);}
	getline(_is,line);istringstream streamline3(line);tradearea = new TradeArea(streamline3 , factory);
	getline(_is,line);istringstream streamline4(line);discardpile = new DiscardPile(streamline4,factory);
	getline(_is,line);istringstream streamline5(line);deck =*(new Deck(streamline5 , factory));

}

//Used to print to a text file

void Table::print(std::ostream& _os){

	_os<<"player1 " << players[0]->getMaxNumChains()<<" ";
	players[0]->printToFile(_os);
	_os<<"player2 " <<players[1]->getMaxNumChains() <<" ";
	players[1]->printToFile(_os);
	_os <<"tradearea "<< *tradearea<<" end"<<endl;
	_os<<"discard ";
	discardpile->print(_os);
	_os<<" end"<<endl;
	_os <<"deck "<<deck<<" end"<<endl;	
	
}

//insertion Operator

std::ostream& operator<<(std::ostream& _os, const Table& _table){
_os << *_table.players[0]<<"\n"<<endl;
_os <<*_table.players[1] <<"\n"<<endl;
_os<<"trade Area : "<<*_table.tradearea<<"\n"<<endl;
_os <<"Discard pile: "<<*_table.discardpile<<"\n\n\n"<<endl;	
}

//Determines the winner

bool Table::win(string& winner){
	bool winnerfound = false;
	if(deck.isEmpty()){
		winnerfound = true;
		winner = players[0]->getName();
		if(players[0]->getNumCoins()<players[1]->getNumCoins() ){winner = players[1]->getName();}
		else if(players[0]->getNumCoins()==players[1]->getNumCoins()){winnerfound = false;}}}
