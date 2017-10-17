//
//  ScoreSheet.h
//  CSI2372_Project
//
//  Created by Rami Taleb on 2017-10-17.
//  Copyright © 2017 Rami Taleb. All rights reserved.
//

#ifndef ScoreSheet_h
#define ScoreSheet_h

#include <string>
#include <iostream>
#include <vector>

enum Colour {RED, YELLOW, BLUE};

struct Dice {
    Colour a;
    int num;
};

class ScoreSheet {
    std::string name;
    int redScore = 0, yellowScore = 0, blueScore = 0, overallScore = 0, failedAttempts = 0;
    std::vector<Dice> redDice, yellowDice, blueDice;
public:
    ScoreSheet(std::string name);
    void print(std::ostream &o);
    void score(std::vector<Dice> dice, Colour colour, int pos);
};

#endif /* ScoreSheet_h */
