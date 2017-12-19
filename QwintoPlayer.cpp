#include "QwintoPlayer.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
/*
 * single argument constructor
 *
 */
QwintoPlayer::QwintoPlayer(std::string name){
	scoreSheet = new QwintoScoreSheet(name);
}

/*
 * gathers input before a qwinto roll
 *
 */
void QwintoPlayer::inputBeforeRoll(RollOfDice& _rod){
	if(active){
		
		std::cout<<scoreSheet->getName() <<"\'s turn: "<<std::endl<<"Enter 0, 1, 2 separated by a space to roll red, yellow, blue dice respectively. Add a -1 to end of input: ";

		std::vector<int> list;
		while(true){
			int num;
			std::cin>>num;
			if(num == -1) break;
			
			list.push_back(num);
		}
		for(auto &c : _rod){
			c.setActive(false);
		}
		
		// find all colors chosen in list and set that corresponding dice to active
		for(auto &c : _rod){
			if (std::find(list.begin(), list.end(), c.getColour()) != list.end())
			{
				c.setActive(true);
				c.roll();				
			}
		}
		std::cout<<std::endl;

	}else{
		// nothing inactive players don't do anything while waiting.
		std::cout<<std::endl;
	}
}


void QwintoPlayer::inputAfterRoll(RollOfDice& _rod){
	if(active){
		
		std::cout<<"Enter color of row you want to input your score into: (e.g. red yellow blue): ";		
		std::string word;
		std::cin>>word;	
		for(auto& a : word){
			std::tolower(a);
		}
		std::cout<<std::endl;
		std::cout<< "Enter position you would like to score [0-9]: ";
		int pos;
		std::cin >> pos;
		std::cout<<std::endl;
		Colour c;
		if(word == "red"){
			c = Colour::RED; 
		}else if(word == "yellow"){
			c = Colour::YELLOW;
		}else{
			c = Colour::BLUE;
		}
		
		if(scoreSheet->score(_rod,c,pos)){
			scoreSheet->setScoreOnRow(pos,c,_rod);						
		}else{
			std::cout<<"YOU FAILED TO SCORE" <<std::endl;
		}

	}else{
		
		// determines if inactive players want to score or not

		std::cout<< scoreSheet->getName()<<" want to score? y/n: ";
		std::string decision;
		std::cin>>decision;
		if(decision=="y"){
			std::cout<<"Enter color of row you want to input your score into: (e.g. red yellow blue): ";		
			std::string word;
			std::cin>>word;	
			for(auto& a : word){
				std::tolower(a);
			}	
			std::cout<<std::endl;
			std::cout<< "Enter position you would like to score [0-9]: ";
			int pos;
			std::cin >> pos;
			std::cout<<std::endl;
			Colour c;
			if(word == "red"){
				c = Colour::RED; 
			}else if(word == "yellow"){
				c = Colour::YELLOW;
			}else{
				c = Colour::BLUE;
			}
			if(scoreSheet->score(_rod,c,pos)){
				scoreSheet->setScoreOnRow(pos,c,_rod);						
			}else{
				std::cout<<"YOU FAILED TO SCORE" <<std::endl;
			}	
		}
	}
	
}

ScoreSheet* QwintoPlayer::getScoreSheet() const{
	return scoreSheet;
}

