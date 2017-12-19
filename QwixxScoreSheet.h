//
//  QwixxScoreSheet.h
//  finalproject3
//
//  Created by Rami Taleb on 2017-12-06.
//  Copyright © 2017 Rami Taleb. All rights reserved.
//

#ifndef QwixxScoreSheet_h
#define QwixxScoreSheet_h

#include "ScoreSheet.h"
#include "Colour.h"
#include "QwixxRow.h"
#include <iostream>
#include <vector>
#include <list>
#include "Player.h"


class QwixxScoreSheet : public ScoreSheet{
    friend std::ostream& operator<<(std::ostream &_os, const QwixxScoreSheet &_qss);
private:
    QwixxRow<std::list<RollOfDice>, Colour::BLUE> _rb;
    QwixxRow<std::vector<RollOfDice>, Colour::RED> _rr;
    QwixxRow<std::vector<RollOfDice>, Colour::YELLOW> _ry;
    QwixxRow<std::list<RollOfDice>, Colour::GREEN> _rg;
    int calcTotal() override;
    
public:
    
    QwixxScoreSheet(std::string name):ScoreSheet(name){}

    bool score(const RollOfDice& _rod, const Colour& _c, const int _pos = -1) override;
    
    void setTotal() override;
    bool operator!() override;    
    void setScoreOnRow(const int pos, const Colour& c, const RollOfDice& _rod) override;
protected:
    bool validate(const int _pos, const Colour& _c) const override;
    
};
std::ostream& operator<<(std::ostream &_os, const QwixxScoreSheet &_qss);

#endif /* QwixxScoreSheet_h */
