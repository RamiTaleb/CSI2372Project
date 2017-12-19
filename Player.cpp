#include "Player.h"
/*
 * defaults all players to inactive and scoresheet points to null
 *
 */
Player::Player():active(false), scoreSheet(0){}


bool Player::getActive() const{
	return active;
}
void Player::setActive(const bool& a){
	active = a;
} 

Player::~Player(){
	delete scoreSheet;
}
