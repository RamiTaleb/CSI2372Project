#include "Player.h"
#include<iostream>


//	private:
//		bool active;
//		std::string name;
//	public:
//		Player(bool, std::string);
//		virtual void inputBeforeRoll(RollOfDice&)=0;
//		virtual void inputAfterRoll(RollOfDice&)=0;	

Player::Player():active(false){}
void Player::setActive(const bool &a){
active = a;}		
bool Player::getActive() const{
return active;}
