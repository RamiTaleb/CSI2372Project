#ifndef SCORESHEET_H
#define SCORESHEET_H

#include <iostream>
#include "Colour.h"
class ScoreSheet{
	friend std::ostream& operator<<(std::ostream &_os, QwixxRow<T,COLOUR> &qw);
	private:
		Player *player;
		int _failedA, _oScore;
	public:
		virtual bool score(RollOfDice& _rod, Colour _c, int _pos = -1) = 0;
		virtual int calcTotal() = 0;
		virtual int setTotal();
		bool operator!();
		
	protected:
		virtual bool validate(int _pos) = 0;
};
std::ostream& operator<<(std::ostream &_os, ScoreSheet &_ss);
#endif
