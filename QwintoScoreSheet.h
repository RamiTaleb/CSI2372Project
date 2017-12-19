#ifndef QWINTO_SCORESHEET_H_
#define QWINTO_SCORESHEET_H_
#include "ScoreSheet.h"
#include "Colour.h"
#include "QwintoRow.h"
#include <iostream>
#include "Player.h"
class QwintoScoreSheet : public ScoreSheet{
	friend std::ostream& operator<<(std::ostream &_os, const QwintoScoreSheet &_qss);
	private:		
		QwintoRow<Colour::BLUE> _rb;
		QwintoRow<Colour::RED> _rr;
		QwintoRow<Colour::YELLOW> _ry;	
		int calcTotal() override;	
	
	public:		
		QwintoScoreSheet(std::string name):ScoreSheet(name){}		
		bool score(const RollOfDice& _rod, const Colour& _c, const int _pos = -1) override;		
		void setTotal() override;
		bool operator!() override;
		QwintoScoreSheet& getScoreSheet() const;
		void setScoreOnRow(const int pos, const Colour& c, const RollOfDice& _rod) override;
		
	protected:
		bool validate(const int _pos, const Colour& _c) const override;

};
std::ostream& operator<<(std::ostream &_os, const QwintoScoreSheet &_qss);
#endif
