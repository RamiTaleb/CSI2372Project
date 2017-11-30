
#ifndef ROLL_OF_DICE_H
#define ROLL_OF_DICE_H
#include "Dice.h"
#include <vector>
#include <iterator>
#include "Colour.h"

struct RollOfDice{
	private:
    std::vector<Dice> container_dice{Dice(Colour::RED, 1), Dice(Colour::BLUE, 1), Dice(Colour::WHITE, 1), Dice(Colour::GREEN, 1), Dice(Colour::YELLOW, 1)};
        int sum = 0;
	public:
		RollOfDice();
        RollOfDice(std::vector<Dice> vec);
		void roll();
        //Not used for Quinto
		RollOfDice pair(const int &a, const int &b) const;
        operator int() const {return sum;};
		friend std::ostream& operator<<(std::ostream &_os, RollOfDice& rd);
        int getSum();
    
        typename std::vector<Dice>::iterator begin();
        typename std::vector<Dice>::const_iterator begin() const;
        typename std::vector<Dice>::const_iterator cbegin() const;
        typename std::vector<Dice>::iterator end();
        typename std::vector<Dice>::const_iterator end() const;
        typename std::vector<Dice>::const_iterator cend() const;
};
#endif
