#ifndef QWIXX_ROW_H
#define QWIXX_ROW_H
#include "Colour.h"
#include "RollOfDice.h"
#include <list>

/*
 * Helper structure
 * determines if a row is ascending or not
 * depending on colour
 */
template<const Colour C>
struct DataRowQR{
	static bool _isAscending(){
		bool res = false;
		switch(C){
			case RED:
			case YELLOW:				
				res = true;
				break;
			}			
		return res;
	}
};

template<class T, const Colour COLOUR>
class QwixxRow{
	private:
		T values;
		bool _asc;
		bool _locked;
		std::vector<int> _marked; 
	public:		
		static bool _sharedLock;
		//default constructor to set default values of rows
		//depdending on ascending or not
		//also sends locked to false
		QwixxRow<T,COLOUR>():_asc{DataRowQR<COLOUR>::_isAscending()}, _locked{false}{
			if(_asc){
				for(int i = 2; i < 13; ++i){
					values.push_back(RollOfDice{COLOUR,i});
				}
			}else{
				for(int i = 12; i > 1; --i){
					values.push_back(RollOfDice{COLOUR,i});
				}
			}
			
		}
		QwixxRow<T,COLOUR>& operator+=(const RollOfDice& rd);
		int getRightMost() const;
		void _willLock();
		int getRowAmount() const;
		bool isLocked() const {return _sharedLock;}
		friend std::ostream& operator<<(std::ostream &_os, const QwixxRow<T,COLOUR> &qw){
			_os<<"|";
			if(qw._asc){
				bool flag = false;
				for(int i = 0; i < 11; ++i){
					
					for(int j = 0; j < qw._marked.size(); ++j){
					if(qw._marked[j] == i+2)  {
						flag = true;
					}					
				} 
				
				if(flag){
					_os<<"XX";
					flag = false;
				}else if(i+2 < 10){
					_os<<" " << i+2;
				}else{
					_os<<i+2;
				}
				_os<<"|";
				}
			}else{
				bool flag = false;
				for(int i = 14; i > 3; --i){
					for(int j = 0; j < qw._marked.size(); ++j){
					if(qw._marked[j] == i-2)  {
						flag = true;
					}					
				} 
				
				if(flag){
					_os<<"XX";
					flag = false;
				}else if(i-2 < 10){
					_os<<" " << i-2;
				}else{
					_os<<i-2;
				}
				_os<<"|";
				}
			}		
			if(_sharedLock){
				_os<<" L";
			}else{
				_os<<" U";
			}
			_os<<std::endl;
		}
};

template<class T, const Colour COLOUR>
bool QwixxRow<T,COLOUR>::_sharedLock = false;

template<class T, const Colour COLOUR>
QwixxRow<T,COLOUR>& QwixxRow<T,COLOUR>::operator+=(const RollOfDice& rd){	
	if(!_sharedLock){
		if(_asc){
		for(int i = 0; i < _marked.size(); ++i){
			if(_marked[i] >= rd){
				throw "YOU FAILED A THROW";
			}
		}		
		_marked.push_back(rd);
		_willLock();		
	}else{
		for(int i = 0; i < _marked.size(); ++i){
			if(_marked[i] <= rd){
				throw "YOU FAILED A THROW";
			}
		}
		_marked.push_back(rd);
		_willLock();
	}
	}else{		
		throw "YOU FAILED A THROW BECAUSE YOU TRIED TO SCORE ON A LOCKED ROW";
	}
	return *this;
	
}

//checks to see if a row is set to lock
//called after scoring in a row
template<class T, const Colour COLOUR>
void QwixxRow<T,COLOUR>::_willLock(){
	if(_asc){
		bool flag = false;
		for(int i = 0; i < _marked.size(); ++i){
			if(_marked[i] == 12){
				flag = true;
			}
		}
		if(_marked.size() >= 5 && flag){
			_locked = true;
			_sharedLock = true;
		}
	}else{
		bool flag = false;
		for(int i = 0; i < _marked.size(); ++i){
			if(_marked[i] == 2){
				flag = true;
			}
		}
		if(_marked.size() >= 5 && flag){
			_locked = true;
			_sharedLock = true;
		}
	}
}

//gets the right most marked value in a row
//to help determine if a pos in a row is scorable
template<class T, const Colour COLOUR>
int QwixxRow<T,COLOUR>::getRightMost() const{
	if(!_marked.empty()){
		return _marked[_marked.size()-1];
	}else{
		// indicates marked is empty -- place anywhere
		if(_asc){
			return 2;
		}else{
			return 12;
		}
	}
	
}

//gets amount of marked positions in a row
template<class T, const Colour COLOUR>
int QwixxRow<T,COLOUR>::getRowAmount() const{
	if(_locked){
		return _marked.size() + 1;
	}else{
		return _marked.size();
	}
	
}
#endif


