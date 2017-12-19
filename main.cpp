#include <iostream>
#include <algorithm>
#include "QwintoScoreSheet.h"
#include "QwintoPlayer.h"
#include "RollOfDice.h"
#include "Dice.h"
#include <limits>
#include "QwixxPlayer.h"
#include "QwixxScoreSheet.h"


int main(int argc, char** argv) {

	std::cout<<"Enter 0 for Qwinto, 1 for Qwixx: ";
	int gameChoice;
	std::cin >> gameChoice;
	
	std::cout<<"Enter number of players (at least 2): ";
	int numPlayers;
	std::cin>>numPlayers;
	
	std::vector<Player*> playerVec;
	RollOfDice* _rod;
	if(gameChoice == 0){	
		for(int i = 0; i < numPlayers; ++i){
			std::cout<< "Enter player's name: ";
			std::string name;
			std::cin >> name;
			playerVec.push_back(new QwintoPlayer{name});			
		}
		_rod = new RollOfDice({Dice{Colour::RED},Dice{Colour::YELLOW},Dice{Colour::BLUE}});
	}else{
			for(int i = 0; i < numPlayers; ++i){
			std::cout<< "Enter player's name: ";
			std::string name;
			std::cin >> name;
			playerVec.push_back(new QwixxPlayer{name});			
		}	
		_rod = new RollOfDice({Dice{Colour::RED,true},Dice{Colour::YELLOW,true},Dice{Colour::BLUE,true},Dice{Colour::GREEN,true},Dice{Colour::WHITE,true},Dice{Colour::WHITE,true}});
	}

	bool flag = true;

	while(flag){
		for(auto &c : playerVec){
			if(!*(c->getScoreSheet())){			
				flag = false;
				break;
			}
			c->setActive(true);					
			c->inputBeforeRoll(*_rod);
			std::cout<<std::endl<<"Roll: " <<std::endl << *_rod;
			if(gameChoice == 0){
				std::cout<<*dynamic_cast<QwintoScoreSheet*>((c->getScoreSheet()))<<std::endl;
			}else{
				std::cout<<*dynamic_cast<QwixxScoreSheet*>((c->getScoreSheet()))<<std::endl;
			}	
			c->inputAfterRoll(*_rod);
			c->getScoreSheet()->setTotal();
			if(gameChoice == 0){
				std::cout<<*dynamic_cast<QwintoScoreSheet*>((c->getScoreSheet()))<<std::endl;
			}else{
				std::cout<<*dynamic_cast<QwixxScoreSheet*>((c->getScoreSheet()))<<std::endl;
			}
			for(auto &d : playerVec){
				if(!d->getActive()){	
					if(!*(d->getScoreSheet())){
						flag = false;
						break;
					}	
					if(gameChoice == 0){
						std::cout<<*dynamic_cast<QwintoScoreSheet*>((d->getScoreSheet()))<<std::endl;
					}else{
						std::cout<<*dynamic_cast<QwixxScoreSheet*>((d->getScoreSheet()))<<std::endl;
					}
					d->inputAfterRoll(*_rod);					
					d->getScoreSheet()->setTotal();
					if(gameChoice == 0){
						std::cout<<*dynamic_cast<QwintoScoreSheet*>((d->getScoreSheet()))<<std::endl;
					}else{
						std::cout<<*dynamic_cast<QwixxScoreSheet*>((d->getScoreSheet()))<<std::endl;
					}
				}
			}
			c->setActive(false);		
		}
		
	}
	
	std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;
	std::cout<<"////GAME IS OVER... PRINTING OUT SCORE SHEETS OF ALL PLAYERS////"<<std::endl;
	std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl<<std::endl<<std::endl;
	int highest = std::numeric_limits<int>::min();
	Player* winner;
		for(auto& player:playerVec){
			player->getScoreSheet()->setTotal();
			if(highest < player->getScoreSheet()->getScore()){
				highest = player->getScoreSheet()->getScore();
				winner = player;
			}		
			if(gameChoice == 0){
						std::cout<<*dynamic_cast<QwintoScoreSheet*>((player->getScoreSheet()))<<std::endl;
					}else{
						std::cout<<*dynamic_cast<QwixxScoreSheet*>((player->getScoreSheet()))<<std::endl;
					}
		}
		
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout<<"Winner is: " << winner->getScoreSheet()->getName() << " with " << highest << " points!" <<std::endl;	
	
	
				if(gameChoice == 0){
						std::cout<<*dynamic_cast<QwintoScoreSheet*>((winner->getScoreSheet()))<<std::endl;
					}else{
						std::cout<<*dynamic_cast<QwixxScoreSheet*>((winner->getScoreSheet()))<<std::endl;
					}
	return 0;
}

