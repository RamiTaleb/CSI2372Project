#ifndef ROLL_OF_DICE_H
#define ROLL_OF_DICE_H
#include "Dice.h"
#include <vector>
#include <iterator>
#include "Colour.h"

/*
 * container structure that holds multiple dice
 *
 *
 */
struct RollOfDice{
	friend std::ostream& operator<<(std::ostream &_os, const RollOfDice& rd);
	private:
    	std::vector<Dice> container_dice;
        int sum;
	public:
        RollOfDice(const std::vector<Dice>& vec);
        RollOfDice(const Colour& c, int i);
		void roll();
		int get_sum();
        //Not used for Quinto
		RollOfDice pair(const int &a, const int &b) const;
        operator int() const {
        	int temp = 0;
			for(auto& c:container_dice)	{
				if(c.getActive()){
					temp+=c.getNum();
				}
			}
			return temp;       	
		};
		
        typename std::vector<Dice>::iterator begin();
        typename std::vector<Dice>::const_iterator begin() const;
        typename std::vector<Dice>::const_iterator cbegin() const;
        typename std::vector<Dice>::iterator end();
        typename std::vector<Dice>::const_iterator end() const;
        typename std::vector<Dice>::const_iterator cend() const;
};
std::ostream& operator<<(std::ostream &_os, const RollOfDice& rd);
#endif

