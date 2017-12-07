#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "RollOfDice.h"
class Player{
	protected:
		bool active;
	public:
		
		Player();
		virtual void inputBeforeRoll(RollOfDice&)=0;
		virtual void inputAfterRoll(RollOfDice&)=0;	
		void setActive(const bool&);
		bool getActive() const;
};

#endif
