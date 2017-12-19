#include "QwixxPlayer.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

QwixxPlayer::QwixxPlayer(std::string name){
scoreSheet = new QwixxScoreSheet(name);
}

/*
 * gets input of active and inactive players after a roll
 * if the player is active get pair of rollofdice that corresponds to
 * color of choice and 1 white die
 * 
 *
 */
void QwixxPlayer::inputAfterRoll(RollOfDice& _rod) {
	if(active){
		std::cout<<scoreSheet->getName() <<"\'s turn: "<<std::endl<<"Choose 1 or 2 scores (enter 1 or 2): ";
		int numScores;
		std::cin>>numScores;		
		std::cout<<"Enter color of row you want to input your score into: (e.g. red yellow blue green): ";		
		std::string colourChoice;
		std::cin>>colourChoice;			
		std::cout<<std::endl;	
			
		for(auto& a : colourChoice){
			std::tolower(a);
		}
		
		Colour c;
		if(colourChoice == "red"){
			c = Colour::RED;
		}else if(colourChoice == "yellow"){
			c = Colour::YELLOW;
		}else if(colourChoice == "blue"){
			c = Colour::BLUE;
		}else{
			c = Colour::GREEN;
		}
		std::cout<<"Pick white dice to add score with color: 4 or 5: ";
		int whiteNum;
		std::cin>>whiteNum;
		RollOfDice rd = _rod.pair(c,whiteNum);
		if(scoreSheet->score(rd,c)){
			scoreSheet->setScoreOnRow(-1,c,rd);
			scoreSheet->setTotal();
		}else{
			std::cout<<"YOU FAILED TO SCORE: " << scoreSheet->getName()<<std::endl;
		}
		// if active player wants 2 scores, must pair the two white dice and add it to their score sheet
		if(numScores == 2){
			std::cout<<*dynamic_cast<QwixxScoreSheet*>(scoreSheet)<<std::endl;
			std::cout<<"Enter color of row you want to input your score into: (e.g. red yellow blue green): ";		
			std::string colorChoice2;
			std::cin>>colorChoice2;	
			Colour c2;
			if(colorChoice2 == "red"){
				c2 = Colour::RED;
			}else if(colorChoice2 == "yellow"){
				c2 = Colour::YELLOW;
			}else if(colorChoice2 == "blue"){
				c2 = Colour::BLUE;
			}else{
				c2 = Colour::GREEN;
			}
			RollOfDice rw = _rod.pair(4,5);
			std::cout<<rw<<std::endl;
			if(scoreSheet->score(rw,c2)){
				scoreSheet->setScoreOnRow(-1,c2,rw);
			}else{
				std::cout<<"YOU FAILED TO SCORE: " << scoreSheet->getName()<<std::endl;
			}
		}		
	}else{
		// determines if inactive player want to score
		std::cout<<scoreSheet->getName()<< ", want to score? y/n: ";
		std::string decision;
		std::cin>>decision;
		if(decision=="y"){
			std::cout<<"Enter color of row you want to input your score into: (e.g. red yellow blue green): ";		
			std::string word;
			std::cin>>word;	
			for(auto& a : word){
				std::tolower(a);
			}	
			std::cout<<std::endl;
			Colour c;
			if(word == "red"){
				c = Colour::RED;
			}else if(word == "yellow"){
				c = Colour::YELLOW;
			}else if(word == "blue"){
				c = Colour::BLUE;
			}else{
				c = Colour::GREEN;
			}
			RollOfDice rw = _rod.pair(4,5);
			if(scoreSheet->score(rw,c,-1)){
				scoreSheet->setScoreOnRow(-1,c,rw);
			}else{
				std::cout<<"YOU FAILED TO SCORE" <<std::endl;
			}	
		}
	}
}

void QwixxPlayer::inputBeforeRoll(RollOfDice &_rod) {
	_rod.roll();
}

ScoreSheet* QwixxPlayer::getScoreSheet() const{
return scoreSheet;}



