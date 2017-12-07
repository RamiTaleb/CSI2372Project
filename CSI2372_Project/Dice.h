#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <random>
#include "Colour.h"

/*
 * Helper structure that provides a random number 
 * between 1 - 6 for a dice
 */
struct RandomDice{
	static int rand(){
		static std::random_device rd;
		static std::mt19937 gen(rd());
		static std::uniform_int_distribution<> dis(1,6);
		return dis(gen);
	}
};

/*
 * 
 *
 *
 */
struct Dice {
	friend std::ostream& operator<<(std::ostream &_os, const Dice& d);
    public:    	
    	Dice(Colour colour, int num=0);
    	void roll();    	
        int getNum() const;
        bool getActive() const {return active;}
        void setActive(bool a){active = a;}
        
        Colour getColour() const{return colour;}
    private:
    	const Colour colour;
    	bool active = false;
    	int num;
};
std::ostream& operator<<(std::ostream &_os, const Dice& d);
#endif

