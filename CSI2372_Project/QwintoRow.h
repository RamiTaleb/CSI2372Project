#ifndef QWINTO_ROW_H
#define QWINTO_ROW_H
#include "Colour.h"
#include "RollOfDice.h"
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>

template<const Colour C>
struct DataRow{
	static std::vector<int> _getBonusV(){
		std::vector<int> temp;
		switch(C){
			case RED:				
				temp.push_back(1);
				temp.push_back(5);
				break;
			case BLUE:
				temp.push_back(2);
				temp.push_back(9);
				break;
			case YELLOW:
				temp.push_back(7);		
				break;		
		}			
		return temp;
	}
	static int _getInv(){
		switch(C){
			case RED:
				return 3;
			case BLUE:
				return 4;
			case YELLOW:
				return 5;
		}
	}
};

template<const Colour COLOUR>
class QwintoRow {
	
	private:
		int values[10];
		std::vector<int> bonus;
		int inval;

	public:
    	QwintoRow<COLOUR>():values{},bonus{DataRow<COLOUR>::_getBonusV()},inval{DataRow<COLOUR>::_getInv()}{}
		int& operator[](int i);
		const int& operator[](int i) const;
		bool validate(int pos) const;
		int getRightMostValue() const;
		bool isFull() const;
		int getNumElems() const;
		
		friend std::ostream& operator<<(std::ostream &_os, const QwintoRow<COLOUR> &qw){	
		bool flag = false;	
		_os<<"|";
			for(int i = 0; i < 10; ++i){				
				for(int j = 0; j < qw.bonus.size(); ++j){
					if(qw.bonus[j] == i || qw.bonus[j]-1 == i)  {
						flag = true;
					}					
				} 
				if(i==qw.inval){
					_os<<"XX";
				}else if(qw.values[i] == 0){
					_os<<"  ";
				}else if(qw.values[i] < 10){
					_os<<" " << qw.values[i];
				}else{
					_os<<qw.values[i];
				}				
				if(flag){
					_os<<"%";
				}else{
					_os<<"|";
				}
				flag = false;
			}
			_os<<std::endl;
			return _os;
		}   

};

template<const Colour COLOUR>
int& QwintoRow<COLOUR>::operator[](int i){
	return values[i];
}
template<const Colour COLOUR>
int QwintoRow<COLOUR>::getNumElems() const{
	int numElems = 0;
	for(int i = 0; i < 10; ++i){
		if(values[i] != 0){
			numElems += 1;
		}
	}
	return numElems;
}
template<const Colour COLOUR>
const int& QwintoRow<COLOUR>::operator[](int i) const{
	return values[i];
}

template<const Colour COLOUR>
bool QwintoRow<COLOUR>::validate(int pos) const{

	if(pos<0 || pos > 9) return false;
	if(values[pos] != 0){
		return false;
	}else{
		if(pos == inval){
			return false;
		}
	}
	return true;
}

template<const Colour COLOUR>
int QwintoRow<COLOUR>::getRightMostValue() const{
	return *std::max_element(values,values+10);
}

template<const Colour COLOUR>
bool QwintoRow<COLOUR>::isFull() const{
	for(int i = 0; i < 10; ++i){
		if(i != inval && values[i] == 0){
			return false;
		}		
	}
	return true;
}
#endif

