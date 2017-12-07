#include "QwintoPlayer.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
QwintoPlayer::QwintoPlayer(std::string name):qsc(name){}

void QwintoPlayer::inputAfterRoll(RollOfDice& _rod){
	if(active){
		
		// also ask for position
		std::cout<<"Enter color of row you want to input your score into: (e.g. red yellow blue)";		
		std::string word;
		std::cin>>word;	
		
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
		
		if(qsc.score(_rod,c,pos)){
			qsc.setScoreOnRow(pos,c,_rod);						
		}else{
			std::cout<<"YOU FAILED TO SCORE" <<std::endl;
		}
		qsc.setTotal();
		// word contains color of dice active player wants to choose to put his score in.
		// must find dice that ACTIVE player rolled from inputbeforeroll and use that for screen sheet?
		// will call virtual bool score(RollOfDice& _rod, Colour _c, int _pos = -1); HENCE why we have a qwinto score sheet variable in qwintoplayer

	}else{
		//want to score or not?
		// if yes then color / position
		std::cout<< "Want to score? y/n";
		std::string decision;
		std::cin>>decision;
		if(decision=="y"){
			std::cout<<"Enter color of row you want to input your score into: (e.g. red yellow blue)";		
			std::string word;
			std::cin>>word;	
		
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
		
			if(qsc.score(_rod,c,pos)){
				qsc.setScoreOnRow(pos,c,_rod);						
			}else{
				std::cout<<"YOU FAILED TO SCORE" <<std::endl;
			}
		//qsc.setTotal();	
		}
//		std::cout<<"Enter color of dice you want to score from: (e.g. red yellow)";
//		std::vector<std::string> list;
//		std::string input;
//		std::getline(std::cin,input);
//		std::istringstream iss(input);
//		while(iss){
//			std::string color;
//			iss>>color;
//			list.push_back(color);
//		}
		
				//relate string color to color .. i.e. user inputs "RED" we need to relate that to enum red.. (looks like if/else)
		//input here helps us get score from qwinto score sheet 
	}
	
}
void QwintoPlayer::inputBeforeRoll(RollOfDice& _rod){
	if(active){
		std::cout<<"Enter 0, 1, 2 separated by space to roll red, yellow, blue dice respectively. Write \"-1\" to end input:";

		std::vector<int> list;
		//int input;
		while(true){
			int num;
			std::cin>>num;
			if(num == -1) break;
			
			list.push_back(num);
		}
//		std::getline(std::cin,input);
//		std::istringstream iss(input);
//		while(iss){
//			int word;
//			iss>>word;	
//			list.push_back(word);			
//		}
		for(auto &c : _rod){
			c.setActive(false);
		}
		
		for(auto &c : _rod){
			if (std::find(list.begin(), list.end(), c.getColour()) != list.end())
			{
				c.setActive(true);
				c.roll();
				// marks dice that are rolled from this input as "actively rolled dice" this helps function score from qwinto score sheet^ see above
				
			}
		}
		std::cout<<std::endl;

	}else{
		// nothing really, inactive players don't do anything while waiting.. right?
		std::cout<<std::endl;
	}
}

