#include "RollOfDice.h"
#include "Dice.h"
#include <vector>
#include <iterator>
//	DONE 😘

RollOfDice::RollOfDice() {
}

RollOfDice::RollOfDice(std::vector<Dice> vec) : container_dice{vec} {}

void RollOfDice::roll() {
    sum = 0;
    for (auto& i : container_dice) {
        i.roll();
        sum += i.getNum();
    }
}

int RollOfDice::getSum(){
    return sum;
}

RollOfDice RollOfDice::pair(const int &a, const int &b) const{
    return RollOfDice({container_dice[a], container_dice[b]});
}

std::ostream& operator<<(std::ostream &_os, RollOfDice& rd){
    for (auto& i : rd.container_dice){
        _os << i;
    }
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
