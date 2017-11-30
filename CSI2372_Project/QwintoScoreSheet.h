#ifndef QWINTO_SCORESHEET_H
#define QWINTO_SCORESHEET_H
#include "ScoreSheet.h"
#include "Colour.h"
#include "QwintoRow.h"
class QwintoScoreSheet : public ScoreSheet{
	QwintoRow<COLOUR::BLUE> _rb;
	QwintoRow<COLOUR::RED> _rr;
	QwintoRow<COLOUR::YELLOW> _ry;
	public:
		// implement all pure virtuals
		// insertion operator for printing
};
#endif
