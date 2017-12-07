#ifndef QWINTO_PLAYER_H
#define QWINTO_PLAYER_H
#include "QwintoScoreSheet.h"
#include "Player.h"
#include "Colour.h"
class QwintoPlayer : public Player{
	private:
		QwintoScoreSheet qsc;		
	public:
		QwintoPlayer(std::string name);
		virtual void inputBeforeRoll(RollOfDice& _rod);
		virtual void inputAfterRoll(RollOfDice& _rod);
		QwintoScoreSheet& getScoreSheet() {
		return qsc;}
};
#endif
