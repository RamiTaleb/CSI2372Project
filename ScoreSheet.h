#ifndef SCORESHEET_H
#define SCORESHEET_H
#pragma once
#include <iostream>
#include "Colour.h"
#include "RollOfDice.h"
class Player;

class ScoreSheet{
	friend std::ostream& operator<<(std::ostream &_os, const ScoreSheet &_ss);
	private:
		virtual int calcTotal() = 0;
	public:
		ScoreSheet();
		ScoreSheet(std::string);
		virtual bool score(const RollOfDice& _rod, const Colour& _c, const int _pos = -1) = 0;
		
		virtual void setTotal()= 0;
		virtual bool operator!() = 0;
		void incrementFailedThrow();
		std::string const getName() const;
		int getScore() const;
		virtual void setScoreOnRow(const int pos, const Colour& c, const RollOfDice& _rod) =0;
	protected:
		virtual bool validate(const int _pos, const Colour& _c) const = 0;		
		int _failedA, _oScore;
		std::string name;
};
std::ostream& operator<<(std::ostream &_os, const ScoreSheet &_ss);
#endif
