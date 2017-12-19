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
 * Structure which represents a single die
 * 
 *
 *
 */
struct Dice {
	friend std::ostream& operator<<(std::ostream &_os, const Dice& d);
    public:    	
    	/* must construct dice with a color 
    	 * default face value is 0 (unrolled)
    	 * (makes no sense to default a color)
		 */ 
    	Dice(Colour colour, int num = 0);
    	Dice(Colour colour, bool ac);
    	
    	// gives die random face value 1-6
    	void roll();    
		// returns face value of die	
        int getNum() const;
        
        /*
         * Design decision to set dice as "Active"
         * if they were rolled in most previous inputBeforeRoll
         * inline
         */
        bool getActive() const {return active;}
        void setActive(bool a){active = a;}        
        Colour getColour() const{return colour;}
    private:
    	const Colour colour;
    	bool active;
    	int num = 0;
};
std::ostream& operator<<(std::ostream &_os, const Dice& d);
#endif

