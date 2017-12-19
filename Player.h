#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "RollOfDice.h"
#include "ScoreSheet.h"
class Player{
	protected:
		bool active;
		ScoreSheet *scoreSheet;
	public:		
		Player();
		virtual void inputBeforeRoll(RollOfDice&)=0;
		virtual void inputAfterRoll(RollOfDice&)=0;			
		void setActive(const bool& b);
		bool getActive() const;
		virtual ScoreSheet* getScoreSheet() const = 0;
		virtual ~Player();
};

#endif
