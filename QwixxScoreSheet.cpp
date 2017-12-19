#include "QwixxScoreSheet.h"
#include <map>

//helper structure
//determines amount of points given to a row depending
//on how many positions are marked in the row
struct ScoreMap{
	static std::map<int,int> getScoreMap(){
		std::map<int,int> res;
		res[0] = 0;
		res[1] = 1;
		res[2] = 3;
		res[3] = 6;
		res[4] = 10;
		res[5] = 15;
		res[6] = 21;
		res[7] = 28;
		res[8] = 36;
		res[9] = 45;
		res[10] = 55;
		res[11] = 66;
		res[12] = 78;
		return res;
	}
};


bool QwixxScoreSheet::score(const RollOfDice& _rod, const Colour& _c, const int _pos){
	if(validate(_pos,_c)){
		switch(_c){
			case 0: //red
				if(_rr.getRightMost()<_rod){
					return true;
				}else{
					ScoreSheet::incrementFailedThrow();
					return false;
				}				
			case 1: //yellow
				if(_ry.getRightMost()<_rod){
					return true;
				}else{
					ScoreSheet::incrementFailedThrow();
					return false;
				}
			case 2: //blue
				if(_rb.getRightMost()>_rod){
					return true;
				}else{
					ScoreSheet::incrementFailedThrow();
					return false;
				}
			case 3: //green
				if(_rg.getRightMost()>_rod){
					return true;
				}else{
					ScoreSheet::incrementFailedThrow();
					return false;
				}
		}
	}else{		
		ScoreSheet::incrementFailedThrow();
		return false;
	}
	
	return false;
	
}

//attempts to score a _rod on a pos
//increments failed throws if invalid score
void QwixxScoreSheet::setScoreOnRow(const int pos, const Colour& c, const RollOfDice& _rod){
	try{
	switch(c){
		case 0:
			_rr+=_rod;
			break;
		case 1:
			_ry+=_rod;
			break;
		case 2:
			_rb+=_rod;
			break;
		case 3:
			_rg+=_rod;
			break;
	}
	}catch(std::string msg){
		std::cout<<msg<<std::endl;
		ScoreSheet::incrementFailedThrow();
	}
}


int QwixxScoreSheet::calcTotal(){
	int temp = 0;
	temp-=_failedA*5;
	temp+= ScoreMap::getScoreMap()[_rr.getRowAmount()];
	temp+=ScoreMap::getScoreMap()[_ry.getRowAmount()];
	temp+= ScoreMap::getScoreMap()[_rb.getRowAmount()];
	temp+=ScoreMap::getScoreMap()[_rg.getRowAmount()];
	return temp;
}

void QwixxScoreSheet::setTotal(){
	_oScore = calcTotal();	
}

bool QwixxScoreSheet::operator!(){
		if(_failedA == 4){
		return true;
	}
	int lockedRows = 0;
	if(_rr.isLocked()){
		++lockedRows;
	}
	if(_ry.isLocked()){
		++lockedRows;
	}
	if(_rb.isLocked()){
		++lockedRows;
	}
	if(_rg.isLocked()){
		++lockedRows;
	}
	if(lockedRows >= 2){
		return true;
	}
	return false;
}
//RED,YELLOW,BLUE,GREEN,WHITE
bool QwixxScoreSheet::validate(const int _pos, const Colour& _c) const {
	switch(_c){
		case 0: //red
			return !_rr.isLocked();
		case 1: //yellow
			return !_ry.isLocked();
		case 2: //bl
			return !_rb.isLocked();
		case 3: //green
			return !_rg.isLocked();			
	}
	return false;
}

std::ostream& operator<<(std::ostream &_os, const QwixxScoreSheet &_qss){
	

	_os<<"Player name: " << _qss.name << "             Points: " << _qss._oScore <<std::endl;
	_os<<"        --------------------------------------" <<std::endl;
	_os<<"Red     " << _qss._rr;
	_os<<"        --------------------------------------" <<std::endl;
	_os<<"Yellow  " << _qss._ry;
	_os<<"        --------------------------------------" <<std::endl;
	_os<<"Green   " << _qss._rg;
	_os<<"        --------------------------------------" <<std::endl;
	_os<<"Blue    " << _qss._rb;
	_os<<"        --------------------------------------" <<std::endl;
	_os<<"Failed throws: ";
	
	for(int i = 1; i <= _qss._failedA ;++i){
		_os<< i << " ";
	}
	_os<<std::endl;
	return _os;
	
	
}
