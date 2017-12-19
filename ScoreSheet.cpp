#include "ScoreSheet.h"

ScoreSheet::ScoreSheet():_failedA(0),_oScore(0){}
ScoreSheet::ScoreSheet(std::string name):_failedA(0),_oScore(0),name(name){

}

//public function to increment failed throws
void ScoreSheet::incrementFailedThrow(){
	++_failedA;
}

//public function to get name of player
std::string const ScoreSheet::getName() const{
return name;}

//public function to get name of score
int ScoreSheet::getScore() const{
return _oScore;}

std::ostream& operator<<(std::ostream &_os, const ScoreSheet &_ss){
	return _os;
}
