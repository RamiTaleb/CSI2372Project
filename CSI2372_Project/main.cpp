#include <iostream>
#include <algorithm>
#include "QwintoScoreSheet.h"
#include "QwintoPlayer.h"
#include "RollOfDice.h"
#include "Dice.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool game_ended(std::vector<QwintoPlayer>& p){
	bool res = true;
	for(auto& c : p){
		if(!c.getScoreSheet()){
			res = false;
		}
	}
	return res;
}
int main(int argc, char** argv) {
//	int arr[] = {0,1,2,3,432,345,32,42};
//	std::cout<<*std::max_element(arr,arr+8)<<std::endl;
//	QwintoScoreSheet h;
//	
//	std::cout<< !h << std::endl;
//		std::cout<< true << std::endl;
//		std::cout<<h<<std::endl;


//---------------------------------------
//add game version decision
std::vector<QwintoPlayer> playerVec;
QwintoPlayer p1{"hisham"};
QwintoPlayer p2{"Rami"};
playerVec.push_back(p1);
playerVec.push_back(p2);

Dice d1(Colour::RED);
Dice d2(Colour::YELLOW);
Dice d3(Colour::BLUE);
RollOfDice _rod({d1,d2,d3});


while(game_ended){
	for(auto &c :playerVec){
		c.setActive(true);				
		c.inputBeforeRoll(_rod);
		std::cout<<_rod<<std::endl;
		std::cout<<c.getScoreSheet()<<std::endl;
		c.inputAfterRoll(_rod);
		c.getScoreSheet().setTotal();
		std::cout<<c.getScoreSheet()<<std::endl;
		for(auto &d : playerVec){
			if(!d.getActive()){				
				std::cout<<d.getScoreSheet()<<std::endl;
				d.inputAfterRoll(_rod);
				d.getScoreSheet().setTotal();
				std::cout<<d.getScoreSheet()<<std::endl;
			}
		}
		c.setActive(false);
		
	}

}

	return 0;
}
