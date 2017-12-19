#include "RollOfDice.h"
#include "Dice.h"
#include <vector>
#include <iterator>

//constructor which takes a vector of dice
RollOfDice::RollOfDice(const std::vector<Dice>& vec) : container_dice{vec},sum{0} {}

//2 argument constructor
RollOfDice::RollOfDice(const Colour& c, int i){
	container_dice.push_back(Dice(c, i));
	sum=i;
}

//gets the overall sum of die in a rollOfDice
int RollOfDice::get_sum(){
	sum=0;
	for (auto& i : container_dice) {
        sum+=i.getNum();
    }
    return sum;
}

void RollOfDice::roll() {   
	sum = 0; 
    for (auto& i : container_dice) {
        i.roll();
        sum+=i.getNum();
    }
}

RollOfDice RollOfDice::pair(const int &a, const int &b) const{
    return RollOfDice({container_dice[a], container_dice[b]});
}

std::ostream& operator<<(std::ostream &_os, const RollOfDice& rd){
	int count = 0;
    for (auto& i : rd.container_dice){
    
    	if(i.getActive()){
    		_os <<count<<": "<< i;
    		++count;
		}
        	
    }
    _os<<std::endl;
    return _os;
}

typename std::vector<Dice>::iterator RollOfDice::begin() {
    return container_dice.begin();
}

typename std::vector<Dice>::const_iterator RollOfDice::begin() const {
    return container_dice.begin();
}

typename std::vector<Dice>::const_iterator RollOfDice::cbegin() const {
    return begin();
}

typename std::vector<Dice>::iterator RollOfDice::end() {
    return container_dice.end();
}

typename std::vector<Dice>::const_iterator RollOfDice::end() const {
    return container_dice.end();
}

typename std::vector<Dice>::const_iterator RollOfDice::cend() const {
    return end();
}

