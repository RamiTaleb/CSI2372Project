//
//  QuixxPlayer.h
//  finalproject3
//
//  Created by Rami Taleb on 2017-12-06.
//  Copyright © 2017 Rami Taleb. All rights reserved.
//

#ifndef QuixxPlayer_h
#define QuixxPlayer_h
#include "QwixxScoreSheet.h"
#include "Player.h"
#include "Colour.h"

class QwixxPlayer : public Player{
private:
    QwixxScoreSheet qsc;
public:
    QwixxPlayer(std::string name);
    virtual void inputBeforeRoll(RollOfDice& _rod);
    virtual void inputAfterRoll(RollOfDice& _rod);
    QwixxScoreSheet& getScoreSheet() {
        return qsc;}
};

#endif /* QuixxPlayer_h */

