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
    Dice d = {RED, 1};
    s.print(std::cout);
    return 0;
}
