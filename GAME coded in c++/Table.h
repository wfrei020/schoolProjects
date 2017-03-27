#ifndef _TABLE_H
#define _TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"

#include <string>
//Header files not commented
using std::string;

class Table{
	
//since the table is a manager it is public to classes	
	public:
		Deck deck ;
		DiscardPile* discardpile;
		TradeArea* tradearea;
		Player* players[2];	
		Table(string d_player1, string d_player2, CardFactory*);
		Table(std::istream& , CardFactory*);
		~Table();
		bool win(string&);
		void print(std::ostream& _os);
		friend std::ostream& operator<<(std::ostream& , const Table&);
		
	
};
#endif
