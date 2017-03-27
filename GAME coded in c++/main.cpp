/*	Developers: Walter Freire 6399015 AND Amin Ghiasian 6703677
 *				CSI2372 Project
 *				December 8, 2016
 *				
 *	Note:  There are still a few bugs we were not able to fully resolve
 *			In general it does do the basic functionalities
 *			main function at the end
 */


#include "Table.h"
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <sstream>
#include "CardFactory.h"


/*  list of functions:
 *			getLetter() : get the letter of the Card
 *			tryToChain(): used to chain a Card to an existing Chain or make new
 *			sellChainMethod(): used to sell a chain
 *			tradeAreaToChain() : used to move cards from trade area to a chain
 *			pauseGame() : function called to pause the game and print
 *			playGame() : function called to play the game for each player
 *			main() : initializer
 */

using std::cout;
using std::cin;
using std::string;
int playersTurn = 0;
string player1Name,player2Name;
Table* gameTable;
CardFactory* factory = CardFactory::getFactory();
fstream ioFile;
//Some functions

std::string getLetter(Card* find){
std::string letter = "Q";
if(find->getName()=="Hematite"){letter = "H";}
else if(find->getName()=="Obsidian"){letter = "O";}
else if(find->getName()=="Malachite"){letter = "M";}
else if(find->getName()=="Turquoise"){letter = "T";}
else if(find->getName()=="Ruby"){letter = "R";}
else if(find->getName()=="Amethyst"){letter = "A";}
else if(find->getName()=="Emerald"){letter = "E";}
return letter;
}

//Try to chain takes in the players turn, and as well as the card it would like to try to chain
//if it finds a chain with the same card it will add to chain, or if its an empty chain it will start a new chain
//if it was successfull it will return true, if it fail it will print why and return false
bool tryToChain(int i, Card* card){
					int j = 0;
					bool done = false;
				
				while(j< gameTable->players[i]->getMaxNumChains()){
		
				if(!gameTable->players[i]->chains[j]){//need to fix
					
					gameTable->players[i]->getNewChain((card)->getName() ,j);
					cout<<"you have created a new chain with your card!\n\nType\tChain:\n\n";
					done = true;
					for(int k = 0;k<gameTable->players[i]->getMaxNumChains();k++){
						if(gameTable->players[i]->chains[k]){
						
					cout<<(*gameTable->players[i])[k+1]<<"\n\n";}
					}
						break;
					}
					else{
		
				try{
				if(	gameTable->players[i]->chains[j]){
				(*gameTable->players[i])[j+1]+=(card);
				done = true;

				break;
			}
		}catch(std::invalid_argument e){cout<<"\n\nYour card does not match with any chain\n\n";
							cout<<"Available chains:\n\nType\tChain";
					for(int k = 0;k<gameTable->players[i]->getMaxNumChains();k++){
							if(gameTable->players[i]->chains[k]){
					cout<<(*gameTable->players[i])[k+1]<<"\n\n";}
					}
					
					
					
		}
	}
		
		j++;
	}
	//changes end<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,,
	return done;
}

//The method is used to sell a chain, it takes the players turn as the input, then it display the players chains
//it will then proceed to ask to pick a chain to sell and it sell it unless there are no chains to sell

void sellChainMethod(int i ){	
	
	
			cout<<"What Chain would you like to sell?\t"<<endl;


			int sell;
				//need to ask what chain to sell;
			int	j = 0;

			while(j < gameTable->players[i]->getMaxNumChains()){
					if(gameTable->players[i]->chains[j]){
						if(!(*gameTable->players[i])[j+1].isEmpty()){
						
				cout<<"\t"<<(*gameTable->players[i])[j+1]<<"\t"<<j+1<<endl;}
				else{cout<<"empty\n";
				}
			}
				j++;
			}
				cout<<"please pick a Chain to sell : "<<endl;
				cin>>sell;
				if(sell == 1){
			(*gameTable->players[i])+=	(*gameTable->players[i])[1].sellChain();
			delete gameTable->players[i]->chains[0];
			cout<<"sold a chain\n";
				
				}
				else if(sell == 2){
							(*gameTable->players[i])+=	(*gameTable->players[i])[2].sellChain();
										delete gameTable->players[i]->chains[1];
										cout<<"sold a chain\n";	
				}
				
					else if(sell == 3 && gameTable->players[i]->getMaxNumChains()== 3){
							(*gameTable->players[i])+=	(*gameTable->players[i])[3].sellChain();
										delete gameTable->players[i]->chains[2];
										cout<<"sold a chain\n";	
				}
cout<<"after the destruction";
			//	gameTable->players[i]->arrangeChain();

}

//this method takes in player turn and if it should dicard card from trade area or not
//the method will ask the user to move any card from trade area to chain
//if the user enters none it ends and will return true
			bool tradeAreaToChain(int i,bool discard){
				
							std::string keep;

			cout<<"Enter the card you would like to chain or enter none: ";
			cin>>keep;
			if(keep == " none"){
			return true;
			}
			else{
				for(auto iter=gameTable->tradearea->tradeArea.begin();iter != gameTable->tradearea->tradeArea.end();iter++){
					if((*iter)->getName() == keep || getLetter(*iter) == keep ){
						
						if(tryToChain(i,*iter)){
						gameTable->tradearea->trade((*iter)->getName());
						return false;
					}
					else{if(discard){*gameTable->discardpile+=*iter;}//need to delete card in tradetable
					}
					}
					else if(keep == "none"){return true;
					}
				
					
				}
				cout<<"Please enter a card available! \n";
					return false;
			}
			}
//pausing the game
void pauseGame(){
	ioFile.open("savedGame.txt", ios::out);
	ioFile<<playersTurn<<endl;
	gameTable->print(ioFile);
	ioFile.close();
	
	//need to print to file savedGame.txt;
}

//play game algorithm

void playGame(){
	//check players turn
	int i = playersTurn;
	while(!gameTable->deck.isEmpty()){
	i = playersTurn;
	cout<<"\n";
	cout<<*gameTable;
	cout<<"\n\n";
	int choice;
	//ask to buy a chain, pause game or play
		if(gameTable->players[i]->getMaxNumChains() == 2){
		cout<<"Buy Chain\t\t\t1\n\n" <<endl;}
		cout<<"pause game\t\t\t2\n\n"<<endl;
		cout<<"play\t\t\t\t3\n\n"<<endl;
		cin>>choice;
		if(choice ==1){
		try{
		gameTable->players[i]->buyThirdChain();}
		catch(std::exception& e){cout<<"\nnot enough Coins\n";
		}
		
		}
		else if(choice == 2){
			pauseGame();
		return;
		}
	
	//if play game
			//display table
		//for each player loop using 0 for player 1 and 1 for player 2
		cout<<" "<<gameTable->players[i]->getName()<<"s turn,\n\n"<<endl;
//cgecks to see if trade area is empty
		while(!gameTable->tradearea->isEmpty()){
			cout<<"Which Card Would you like to Chain or Discard : "<<*gameTable->tradearea<<" \n";
			if(tradeAreaToChain(i , true)){break;}
			
		}
		//move rest to discard pile
			for(auto iter=gameTable->tradearea->tradeArea.begin();iter != gameTable->tradearea->tradeArea.end();iter++){*gameTable->discardpile+=*iter;}
			std::string replay = "N";
		//play a hand to the trade area
		//try to chain the card
		//and ask to sell the chain
		//needs to handle conditions to check if pointers are empty or else it will crash
		//finally it will infinitely loop to allow user to play top card of deck until user does not want to
		do{
			*gameTable->tradearea+=	gameTable->players[i]->getPlayerHand().play();
		
			if(gameTable->players[i]->getNumChains()  == gameTable->players[i]->getMaxNumChains()){
			
			if(!tryToChain(i,gameTable->tradearea->tradeArea.back())){
			
				if(gameTable->players[i]->getNumChains()  ==gameTable->players[i]->getMaxNumChains()){
				cout<<"you need to sell a chain or continue!\n";
				string ans;
				cin >>ans;
				if(ans == "continue"){
					replay = "N";
				break;}
				else{
				sellChainMethod(i);}
			}
			}
			}
			else{
			try{
			tryToChain(i,gameTable->tradearea->tradeArea.back());}
			catch(invalid_argument e){ replay ="N";
			}
			}
			if(!gameTable->players[i]->getPlayerHand().sizeOf() == 0){
				cout<<"your top card in your hand is :  "<<*gameTable->players[i]->getPlayerHand().top()<<endl;
				cout<<"would you like ot play top card(Y/N)?\t";
				cin>>replay;
			}
			
		}while(replay == "Y" || replay == "y");
		
		//shows current hand and asks to discard pile
		std::string discardCard;
		cout<<"your current hand is : "<<gameTable->players[i]->getPlayerHand()<<endl;
		cout<<"would you like to discard a card from your hand (Y/N): ";
		cin>>discardCard;
		if(discardCard == "Y" &&gameTable->players[i]->getPlayerHand().sizeOf() != 0){
			int numb;
			while(1){
			
		cout<<"please select a card from : 1-"<<gameTable->players[i]->getPlayerHand().sizeOf()<<endl;
		cin>>numb;
		if(numb>0 && numb<=	gameTable->players[i]->getPlayerHand().sizeOf()){
			*gameTable->discardpile += (gameTable->players[i]->getPlayerHand())[numb];
		  	cout<<"\n Top card in discard pile is:\t";
   			cout << *gameTable->discardpile<<"\n\n";
			break;
		}
		else{cout<<"enter a valid number"<<endl;
		}
		

		}
		}

		//the player draws 3 cards and place it in the trade are
		//taking card from discard pile and placing it in the trade table if legal()

				int draw3 = 0;
		while(draw3<3){
		if(!gameTable->deck.isEmpty()){*gameTable->tradearea += gameTable->deck.draw();}
		++draw3;
	}
		cout<<"\n the player draws 3 cards and place it in the trade area:\n";
			cout<<*gameTable->tradearea<<"\n\n";
		
		cout<<"taking a card from discard pile\n";
				while(!gameTable->discardpile->discardEmpty() && gameTable->tradearea->legal(gameTable->discardpile->top())){
		
			*gameTable->tradearea += gameTable->discardpile->pickUp();
			cout<<"taking a card from discard pile\n";
		}
		if(gameTable->discardpile->discardEmpty()){cout<<"Discard pile is Empty\n"<<endl;
		}
		else{cout<<"no card in trade area similar to top card of discard pile\n";
		}
					cout<<"current chains : \n"<<endl;
					
						for(int k = 0;k<gameTable->players[i]->getMaxNumChains();k++){
								if(gameTable->players[i]->chains[k]){
					cout<<(*gameTable->players[i])[k+1]<<"\n";}
					}
					
	//again asked to chain a card and sell and chain
	while(1){
		cout<<"please enter a card to chain or leave for next player: "<<*gameTable->tradearea<<endl;
		bool exit = false;
		try{exit = tradeAreaToChain(i,false);
		}
		catch(invalid_argument e){
			std::string sell;
			cout<<"would you like to sell a chain? Y/N "<<endl;
			cin>>sell;
			if(sell == "Y" || sell =="y"){	sellChainMethod(i);	
			}
			else{break;
			}
		
		}
	if(exit || gameTable->tradearea->tradeArea.empty()){
				std::string sell;
			cout<<"would you like to sell a chain? Y/N "<<endl;
			cin>>sell;
			if(sell == "Y" || sell =="y"){	sellChainMethod(i);	
			}
	break;
	}
							
			}
		
		
		//end turn by drawing 2 cards	
		if(!gameTable->deck.isEmpty()){gameTable->players[i]->addToHand(gameTable->deck.draw());}
		if(!gameTable->deck.isEmpty()){gameTable->players[i]->addToHand(gameTable->deck.draw());}
		
	
	
	
	//switch players turn
		
	if(i == 0){playersTurn = 1;}
	else{playersTurn = 0;}	
	//end of loop	
	}

		
	
//show winner
	std::string winner;
	if(gameTable->win(winner)){
		cout<<"The winner of the Game is : "<<winner;
	}
	else{cout<<"the Game is Tied !";
	}
	
	
}

//main
//used to initiate game

int main(){
	int choice;
while(1){
cout<<"New Game\t\t1\n"<<endl;
cout<<"Resume Game\t\t2\n"<<endl;
cout<<"Quit\t\t\t3\n"<<endl;
cin>>choice;
cout<<"\n\n";
//allow for options
//new game
if(choice == 1){
	//name of players
	cout<<"Player 1: ";
	cin>>player1Name;
	cout<<"\nPlayer 2: ";
	cin>>player2Name;
	cout<<endl;
	//create a table for new game and will be controlled
	gameTable = new Table( player1Name,player2Name, factory);
	int draw5 = 5;
	while(draw5>0){gameTable->players[0]->addToHand(gameTable->deck.draw());
	
	gameTable->players[1]->addToHand(gameTable->deck.draw());
	
	draw5--;
	}
	
	playGame();
		break;
}	
//load from game
else if(choice ==2){
	std::string fn{"savedGame.txt"};
	ifstream in(fn);
	if(!in){
		std::cerr<<"could not open file: "<<fn <<endl;
		return -1;
	}
	std::string line;


getline(in,line);
	istringstream streamline(line);
	streamline>>playersTurn;
gameTable = new Table(in, factory );
in.close();
playGame();

break;}
else if(choice == 3){return 0;}
else{cout<<"please enter one of the above selection"<<endl;}
}
	
return 0;	
}

