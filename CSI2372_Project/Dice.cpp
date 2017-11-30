#include "Dice.h"
#include "Colour.h"
#include <iostream>
#include <random>
Dice::Dice(Colour colour, int num) : colour(colour), num(num){
	
}

//test - delete later
Dice::Dice():colour{Colour::RED}, num{0}{
	
}

int Dice::getNum(){
    return num;
}

void Dice::roll(){
	num = RandomDice::rand();
}

std::ostream& operator<<(std::ostream &_os, Dice& d){
	std::string s;
	switch(d.colour){
		case 0:
			s = "RED";
			break;
		case 1:
			s = "YELLOW";
			break;
		case 2:
			s = "GREEN";
			break;
		case 3:
			s = "BLUE";
			break;
		case 4:
			s = "WHITE";
			break;
	}
	_os << "Colour: " << s << " : " << d.num << std::endl;
	return _os;
}
