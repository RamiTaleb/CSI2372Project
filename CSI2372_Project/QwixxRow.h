#ifndef QWIXX_ROW_H
#define QWIXX_ROW_H
#include "Colour.h"
#include "RollOfDice.h"
#include <iterator>

template<class T, const Colour COLOUR>
class QwixxRow{
	public:		
		QwixxRow& operator+=(const RollOfDice& rd);
		friend std::ostream& operator<<(std::ostream &_os, QwixxRow<T,COLOUR> &qw);
};

template<class T, const Colour COLOR>
QwixxRow& QwixxRow::operator+=(const RollOfDice& rd){
    
}
\
template<class T, const Colour COLOR>
std::ostream& operator<<(std::ostream &_os, QwixxRow<T,COLOUR> &qw){
	
}
#endif
