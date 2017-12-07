#include "Dice.h"
#include "Colour.h"
#include <iostream>
#include <random>
Dice::Dice(Colour colour, int num) : colour(colour), num(num){}

int Dice::getNum() const{
    return num;
}

void Dice::roll(){
	num = RandomDice::rand();
}

std::ostream& operator<<(std::ostream &_os, const Dice& d){
	std::string s;
	switch(d.colour){
		case 0:
			s = "RED";
			break;
		case 1:
			s = "YELLOW";
			break;
		case 2:
			s = "BLUE";
			break;
		case 3:
			s = "GREEN";
			break;
		case 4:
			s = "WHITE";
			break;
	}	
	_os << s << " : " << d.num << std::endl;
	return _os;
}

