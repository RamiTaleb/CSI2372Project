//
//  main.cpp
//  CSI2372_Project
//
//  Created by Rami Taleb on 2017-10-17.
//  Copyright © 2017 Rami Taleb. All rights reserved.
//

#include <iostream>
#include "ScoreSheet.h"

int main() {
    ScoreSheet s = ScoreSheet("Rami");

    for (int i = 0; i<10; i++){
        s.redDice.insert(s.redDice.begin()+i, {RED, 0});
    }
    for (int i = 0; i<10; i++){
        s.yellowDice.insert(s.yellowDice.begin()+i, {YELLOW, 0});
    }
    for (int i = 0; i<10; i++){
        s.blueDice.insert(s.blueDice.begin()+i, {BLUE, 0});
    }
    // When assigning specific positions a DICE value.
    //    s.redDice.at(0) = {RED, 2};
    s.print(std::cout);
    return 0;
}
