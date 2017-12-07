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

class QwixxScoreSheet : public ScoreSheet{
    friend std::ostream& operator<<(std::ostream &_os, const QwixxScoreSheet &_qss);
private:
    QwixxRow<std::list<RollOfDice>, Colour::BLUE> _rb;
    QwixxRow<std::vector<RollOfDice>, Colour::RED> _rr;
    QwixxRow<std::vector<RollOfDice>, Colour::YELLOW> _ry;
    QwixxRow<std::list<RollOfDice>, Colour::GREEN> _rg;
    
public:
    
    QwixxScoreSheet(std::string name):ScoreSheet(name){}
    
    bool score(RollOfDice& _rod, Colour& _c, int _pos = -1) override;
    int calcTotal() override;
    void setTotal() override;
    bool operator!() override;
    
    void setScoreOnRow(const int& pos, const Colour& c, const RollOfDice& _rod);
protected:
    bool validate(int& _pos, Colour& _c) const override;
    
};
std::ostream& operator<<(std::ostream &_os, const QwixxScoreSheet &_qss);

#endif /* QwixxScoreSheet_h */
