#include "Dice.h"
#include "Colour.h"
#include <iostream>
#include <random>
/*
 * Two argument constructor
 *
 */
Dice::Dice(Colour colour, int num) : colour{colour}, active{false}, num{num}{}
Dice::Dice(Colour colour,bool active):colour{colour},active{active}{}
/*
 * return face value
 */
int Dice::getNum() const{
    return num;
}
/*
 * set face value random number
 */
void Dice::roll(){
	num = RandomDice::rand();
}

/*
 * print dice color and value
 */
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
	_os <<"Dice " << s << " : " << d.num << std::endl;
	return _os;
}

