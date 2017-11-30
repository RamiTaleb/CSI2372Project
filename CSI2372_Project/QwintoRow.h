
#ifndef QWINTO_ROW_H
#define QWINTO_ROW_H
#include "Colour.h"
#include "RollOfDice.h"
#include <iterator>
#include <iostream>

template<const Colour COLOUR>
class QwintoRow {
	RollOfDice *ar;
    //each row has 30 columns (white spots count as 2)
    
             std::string blue= "||%%|XX||||%%";
             std::string red = "|%%|XX|%%||||";
            std::string yellow = "||||||XX|%%||";

	public:
    QwintoRow() { ar=new RollOfDice[9];};
		RollOfDice& operator[](int i);
		const RollOfDice& operator[](int i) const;
		bool validate(int pos) const;
		std::ostream& operator<<(std::ostream &_os);
    
//
//    struct ColorArray{
//        static constexpr std::string blue(||%%|XX||||%%);
//        static constexpr std::string red = "|%%|XX|%%||||";
//        static constexpr std::string yellow = "||||||XX|%%||";
//        //function to generate random number for dice
//        static int getArray(){
//            static std::random_device rd;
//            static std::mt19937 gen(rd());
//            static std::uniform_int_distribution<> dis(1,6);
//            return dis(gen);
//        }
//    };
};

template<const Colour COLOUR>
RollOfDice& QwintoRow<COLOUR>::operator[](int i){
	return ar[i];
}

template<const Colour COLOUR>
const RollOfDice& QwintoRow<COLOUR>::operator[](int i) const{
	return ar[i];
}

template<const Colour COLOUR>
bool QwintoRow<COLOUR>::validate(int pos) const{
    if (ar[pos] != 0) return false;
    
    if (COLOUR == RED){
        if (pos == 3) return false;
    } else if (COLOUR == BLUE){
        if (pos == 4) return false;
    } else {
        if (pos == 5) return false;
    }
	return true;
}

template<const Colour COLOUR>
std::ostream& QwintoRow<COLOUR>::operator<<(std::ostream &_os){
    std::string temp;
    if(COLOUR == RED){
        temp = red;
    } else if (COLOUR == BLUE){
        temp = blue;
    } else{
        temp = yellow;
    }
    
    for (int i = 0; i < temp.size(); ++i){
        if (i > 9) break;
        _os << temp[i];
        if (ar[i] < 10) _os << ar[i] << " ";
        else _os << ar[i];
    }
	
}
#endif
