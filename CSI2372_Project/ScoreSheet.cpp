//
//  ScoreSheet.cpp
//  CSI2372_Project
//
//  Created by Rami Taleb on 2017-10-17.
//  Copyright © 2017 Rami Taleb. All rights reserved.
//

#include "ScoreSheet.h"

ScoreSheet::ScoreSheet(std::string name) : name(name){}

void ScoreSheet::print(std::ostream & o){
    o << "Player name: " << name << "\t\t\t\t\t\t\t\t\t\t\tPoints: " << overallScore;
    o << "\n------------------------------------------------------------------------";
    o << "\nRed\t\t\t\t|";
    for (std::vector<Dice>::const_iterator i = redDice.begin(); i != redDice.end(); ++i)
        o << (*i).num << '|';
    o << "\n------------------------------------------------------------------------";
    o << "\nYellow\t\t|";
    o << "\n------------------------------------------------------------------------";
    o << "\nBlue\t\t|";
    o << "\n------------------------------------------------------------------------";
    o << "\nFailed Throws: " << failedAttempts;
    o << std::endl;
}


