#ifndef _CHAIN_H
#define _CHAIN_H
#include <stdexcept>
#include <iostream>
/*
*	Base Chain class to control the different type of runtime Gemstones
*
*/
 class Chain_Base{

 	
 public:
 		//contructors and destructors
 		Chain_Base() =default;
 		~Chain_Base(){}
 		//create method to sell chain virtual to call method of type and sellchain to call from base
 		virtual int sell() = 0;
		int sellChain(){this->sell();}
		//following two ,ethods are used to add cards to chain
		virtual	void addCard(Card*) = 0;
		Chain_Base& operator+=(Card* card){this->addCard(card);
		return *this;}
		//checks if it is empty
		virtual bool empty()= 0;
		bool isEmpty(){return this->empty();}
		
		//following is the virtual to print from call of operator<<
		virtual void print(ostream& out) const = 0;
		//following two methods are used to determine the type of chain
		virtual std::string type() = 0;
		std::string nameOfChain(){return this->type();}
 };
//Prints the cards in the chain using insertion operator
 inline std::ostream& operator<<(std::ostream& _os, const Chain_Base& chainB){
	chainB.print(_os);
	return _os;
}
 
 /*Template Class Chain
  */

template <class T>


class Chain:public Chain_Base {
	
	//private variables
	//can hold a vector of type T
		std::vector<T*> chain;
		public:	
			//constructor and destructor
			Chain(T* card){ chain.push_back(card);};
			~Chain();
			Chain(std::istream& _is, CardFactory* factory){	
				string token;
				while(_is>>token){
					if(token != "end"){chain.push_back((T*)factory->getCard(token));}
					else{break;}}}
			//return the type of chain	
			std::string type(){T* typeCard = new T();
				std::string type = typeCard->getName();
				return type;}
			//adds a card type T to the chain	
			void addCard(Card* newCard) {
				T* type = new T();
				if( type->getName() == newCard->getName()){
					chain.push_back((T*)newCard);}
				else{//throw illegal exception
					throw std::invalid_argument("illegal exeption");}}
			
			//sell the chain, had to develop a way to use the getCardperCoin method in Card
			int sell(){
				int numbOfCards = 0;
				int coins = 0;
				int i =1;
				while(i<5){		
					numbOfCards =(*chain.begin())->getCardsPerCoin(i);
					if(numbOfCards == chain.size() ){coins = i;break;}
					else if(numbOfCards > chain.size()){
						if(i = 1) {coins = 0;}
						else{coins = i-1;}}
					i++;}
					
				return coins;}
				
			bool empty(){return chain.empty();
			}
	
			//used to print with insertion operator
			void print(std::ostream& _os)const{
					if(!chain.empty()){
						_os<<chain.back()->getName()<<"\t";
						int size = 0;
						for(auto iter=chain.begin();iter !=chain.end() ; iter++){_os <<**iter<<" ";}}
					else{_os<<"empty";}}
	
};

#endif
