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
    o << "Player name: " << name << "\t\t\t\t\t   Points: " << overallScore;
    o << "\n                -------------------------------";
    o << "\nRed\t\t\t   |";
    int count = 0;
    
    // Print Red Row
    for (std::vector<Dice>::const_iterator i = redDice.begin(); i != redDice.end(); ++i) {
        if (count == 3) {
            o << "XX|";
            ++count;
        }
        else if ((*i).num < 10 && count != 0 && count != 1 && count != 4 && count != 5) {
            if ((*i).num != 0) {
                o << (*i).num << " |";
                ++count;
            } else {
                o << "  |";
                ++count;
            }
        }
        else if ((*i).num < 10 && (count == 0 || count == 1 || count == 4 || count == 5)) {
            if ((*i).num != 0) {
                o << (*i).num << " %";
                ++count;
            } else {
                o << "  %";
                ++count;
            }
        }
        else if ((*i).num >= 10 && count != 0 && count != 1 && count != 4 && count != 5) {
            if ((*i).num != 0) {
                o << (*i).num << " |";
                ++count;
            } else {
                o << "  |";
                ++count;
            }
        }
        else {
            if ((*i).num != 0) {
                o << (*i).num << " %";
                ++count;
            } else {
                o << "  %";
                ++count;
            }
        }
    }
    
    o << "\n             ----------------------------------";
    o << "\nYellow\t\t|";
   
    count = 0;
    // Print Yellow Row
    for (std::vector<Dice>::const_iterator i = yellowDice.begin(); i != yellowDice.end(); ++i) {
        if (count == 5) {
            o << "XX|";
            ++count;
        }
        else if ((*i).num < 10 && count != 6 && count != 7) {
            if ((*i).num != 0) {
                o << (*i).num << " |";
                ++count;
            } else{
                o << "  |";
                ++count;
            }
        }
        else if ((*i).num < 10 && (count == 6 || count == 7)) {
            if ((*i).num != 0) {
                o << (*i).num << " %";
                ++count;
            } else {
                o << "  %";
                ++count;
            }
        }
        else if ((*i).num >= 10 && count != 6 && count != 7) {
            if ((*i).num != 0) {
                o << (*i).num << "|";
                ++count;
            } else {
                o << "  |";
                ++count;
            }
        }
        else {
            if ((*i).num != 0) {
                o << (*i).num << "%";
                ++count;
            } else {
                o << "  %";
                ++count;
            }
        }
    }
    
    o << "\n          ----------------------------------";
    o << "\nBlue\t\t |";
    
    count = 0;
    // Print Blue Row
    for (std::vector<Dice>::const_iterator i = blueDice.begin(); i != blueDice.end(); ++i) {
        if (count == 4) {
            o << "XX|";
            ++count;
        }
        else if ((*i).num < 10 && count != 1 && count != 2 && count != 8 && count != 9) {
            if ((*i).num != 0) {
                o << (*i).num << " |";
                ++count;
            } else {
                o << "  |";
                ++count;
            }
        }
        else if ((*i).num < 10 && (count == 1 || count == 2 || count == 8 || count == 9)) {
            if ((*i).num != 0) {
                o << (*i).num << " %";
                ++count;
            } else {
                o << "  %";
                ++count;
            }
        }
        else if ((*i).num >= 10 && count != 1 && count != 2 && count != 8 && count != 9) {
            if ((*i).num != 0) {
                o << (*i).num << " |";
                ++count;
            } else {
                o << "  |";
                ++count;
            }
        }
        else {
            if ((*i).num != 0) {
                o << (*i).num << " %";
                ++count;
            } else {
                o << "  %";
                ++count;
            }
        }
    }
    o << "\n          -------------------------------";
    o << "\nFailed Throws: " << failedAttempts;
    o << std::endl;
}


