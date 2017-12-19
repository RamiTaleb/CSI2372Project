#include "QwintoScoreSheet.h"


/*
 * 
 * determines if possible to place _rod value at pos at row with color c
 *
 */
bool QwintoScoreSheet::score(const RollOfDice& _rod, const Colour& _c, const int _pos){
	bool validColor = false;
	// checks if color provided by user
	// _c matches atleast one color in _rod
	for(auto &di : _rod){
		if(di.getColour() == _c){
			if(di.getActive()){
				validColor = true;
			}
		}
	}
	//if color is valid
	if(validColor){
		int accumulatedRoll = 0;
		switch(_c){
			case 0: //red row check			
				if(validate(_pos, _c)){
					for(auto& d : _rod){
						if(d.getActive()){
							//accumulate the active dice's values 
							//(where active dice are the dice chosen by the active player)
							accumulatedRoll += d.getNum();
						}
					}
					if(accumulatedRoll > _rr.getRightMostValue()){
						return true;
					}
				}
				ScoreSheet::incrementFailedThrow();
				return false;
			case 1: //yellow
				if(validate(_pos, _c)){
					for(auto& d : _rod){
						if(d.getActive()){
							accumulatedRoll += d.getNum();
						}
					}
					if(accumulatedRoll > _ry.getRightMostValue()){
						return true;
					}
				}
				ScoreSheet::incrementFailedThrow();
				return false;
			case 2: //blue
				if(validate(_pos, _c)){
					for(auto& d : _rod){
						if(d.getActive()){
							accumulatedRoll += d.getNum();
						}
					}
					if(accumulatedRoll > _rb.getRightMostValue()){
						return true;
					}
				}
				ScoreSheet::incrementFailedThrow();
				return false;		
		}
	}else{
		ScoreSheet::incrementFailedThrow();
		return false;
	}
	
	return true;
}



int QwintoScoreSheet::calcTotal(){
	// 1 completed column : if column full, player gets what ever is in bonus % X %
	// 2 completed row: right most val
	// 3 incomplete row: add all values in row
	// 4 mis throw -5 pts
	int temp = 0;
	

	// fulfills 4
	temp -= _failedA*5;
	
	// THIS IS FOR RED ROW
	if(_rr.isFull()){
		// fulfills 2
		temp += _rr.getRightMostValue();
	}else{
		// fulfills 3
		temp += _rr.getNumElems();
	}
	// THIS IS FOR YELLOW ROW
	if(_ry.isFull()){
		// fulfills 2
		temp += _ry.getRightMostValue();
	}else{
		// fulfills 3
		temp += _ry.getNumElems();
	}
	// THIS IS FOR BLUE ROW

	if(_rb.isFull()){
		// fulfills 2
		temp += _rb.getRightMostValue();
	}else{
		// fulfills 3
		temp += _rb.getNumElems();
	}
	
	//-----------covers 2-4 -------------
	
	// COLUMN CHECKING
	if(_rr[1] > 0 && _ry[2] > 0 && _rb[3] > 0){
		temp += _rr[1];
	}
	if(_rr[5] > 0 && _ry[6] > 0 && _rb[7] > 0){
		temp += _rr[5];
	}
	
	if(_rr[6] > 0 && _ry[7] > 0 && _rb[8] > 0){
		temp += _ry[7];
	}
	
	if(_rr[0] > 0 && _ry[1] > 0 && _rb[2] > 0){
		temp += _rb[2];
	}
	
	if(_rr[7] > 0 && _ry[8] > 0 && _rb[9] > 0){
		temp += _rb[9];
	}
	
	return temp;

}

void QwintoScoreSheet::setTotal(){
	_oScore = calcTotal();
}

bool QwintoScoreSheet::operator!(){
	if(_failedA == 4){
		return true;
	}
	int fullRows = 0;
	if(_rr.isFull()){
		++fullRows;
	}
	if(_ry.isFull()){
		++fullRows;
	}
	if(_rb.isFull()){
		++fullRows;
	}
	if(fullRows >= 2){
		return true;
	}
	return false;
}

bool QwintoScoreSheet::validate(const int _pos, const Colour& _c) const{
	switch(_c){
		case 0:
			return _rr.validate(_pos);
		case 1:
			return _ry.validate(_pos);
		case 2:
			return _rb.validate(_pos);
	}
}

/*
 * 
 * helper function to set value pf _rod at pos
 *
 *
 */
void QwintoScoreSheet::setScoreOnRow(const int pos, const Colour& c, const RollOfDice& _rod){
	switch(c){
		case 0:
			_rr[pos] = _rod;
			break;
		case 1:
			_ry[pos] = _rod;
			break;
		case 2:
			_rb[pos] = _rod;
			break;
	}
}
std::ostream& operator<<(std::ostream &_os, const QwintoScoreSheet &_qss){
	

	_os<<"Player name: " << _qss.name << "             Points: " << _qss._oScore <<std::endl;
	_os<<"                -------------------------------" <<std::endl;
	_os<<"Red             " << _qss._rr;
	_os<<"             ----------------------------------" <<std::endl;
	_os<<"Yellow       " << _qss._ry;
	_os<<"          ----------------------------------" <<std::endl;
	_os<<"Blue      " << _qss._rb;
	_os<<"          -------------------------------" <<std::endl;
	_os<<"Failed throws: ";
	
	for(int i = 1; i <= _qss._failedA ;++i){
		_os<< i << " ";
	}
	_os<<std::endl;
	return _os;
	
	
}


