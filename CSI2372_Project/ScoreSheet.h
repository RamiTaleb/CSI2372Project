#ifndef SCORESHEET_H
#define SCORESHEET_H

#include <iostream>
#include "Colour.h"
#include "Player.h"
class ScoreSheet{
	friend std::ostream& operator<<(std::ostream &_os, const ScoreSheet &_ss);

	public:
		ScoreSheet();
		ScoreSheet(std::string);
		virtual bool score(RollOfDice& _rod, Colour& _c, int _pos = -1) = 0;
		virtual int calcTotal() = 0;
		virtual void setTotal()= 0;
		virtual bool operator!() = 0;
		void incrementFailedThrow(){
			++_failedA;
		}		
	protected:
		virtual bool validate(int& _pos, Colour& _c) const = 0;		
		int _failedA, _oScore;
		std::string name;
		Player *player;
};
std::ostream& operator<<(std::ostream &_os, const ScoreSheet &_ss);
#endif
