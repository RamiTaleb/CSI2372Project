#ifndef QWINTO_SCORESHEET_H_
#define QWINTO_SCORESHEET_H_
#include "ScoreSheet.h"
#include "Colour.h"
#include "QwintoRow.h"
#include <iostream>

class QwintoScoreSheet : public ScoreSheet{
	friend std::ostream& operator<<(std::ostream &_os, const QwintoScoreSheet &_qss);
	private:		
		QwintoRow<Colour::BLUE> _rb;
		QwintoRow<Colour::RED> _rr;
		QwintoRow<Colour::YELLOW> _ry;		
	
	public:
		
		QwintoScoreSheet(std::string name):ScoreSheet(name){}
		
		bool score(RollOfDice& _rod, Colour& _c, int _pos = -1) override;
		int calcTotal() override;
		void setTotal() override;
		bool operator!() override;
		
		void setScoreOnRow(const int& pos, const Colour& c, const RollOfDice& _rod);
	protected:
		bool validate(int& _pos, Colour& _c) const override;

};
std::ostream& operator<<(std::ostream &_os, const QwintoScoreSheet &_qss);
#endif
