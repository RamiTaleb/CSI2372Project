//
//  QuixxPlayer.cpp
//  finalproject3
//
//  Created by Rami Taleb on 2017-12-06.
//  Copyright © 2017 Rami Taleb. All rights reserved.
//

#include "QuixxPlayer.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

//class QwixxPlayer : public Player{
//private:
//    QwixxScoreSheet qsc;
//public:
//    QwixxPlayer(std::string name);
//    virtual void inputBeforeRoll(RollOfDice& _rod);
//    virtual void inputAfterRoll(RollOfDice& _rod);
//    QwixxScoreSheet& getScoreSheet() {
//        return qsc;}
//};

QwixxPlayer::QwixxPlayer(std::string name):qsc(name){}

void QwixxPlayer::inputAfterRoll(RollOfDice& _rod) {

}

void QwixxPlayer::inputBeforeRoll(RollOfDice &_rod) {
    
}
