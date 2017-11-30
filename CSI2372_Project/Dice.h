#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <random>
#include "Colour.h"


struct RandomDice{
    //function to generate random number for dice
	static int rand(){
		static std::random_device rd;
		static std::mt19937 gen(rd());
		static std::uniform_int_distribution<> dis(1,6);
		return dis(gen);
	}
};
struct Dice {
	
    public:
    	Dice();
//        Dice(const RandomDice& rd);
    	Dice(Colour colour, int num);
    	void roll();
    	friend std::ostream& operator<<(std::ostream &_os, Dice& d);
        int getNum();
    private:
    	const Colour colour;
    	int num;
};

std::ostream& operator<<(std::ostream &_os, Dice& d);
#endif
