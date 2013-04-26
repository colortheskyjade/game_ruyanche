#include "bullet.h"

Bullet::Bullet(QPixmap* p, int x, int y, bool up, int attack, bool red, bool heart) : Thing(p, x, y, 0 , 0), attack(attack){
	valid = true;
	vx = 0;
	if(up){
		vy = -2;
	}
	else{
		vy = 2;
	}
	if(red){
		w = 20;
	}
	else{
		w = 2;
	}
	if(heart){
		h = 20;
		vy = 1;
	}
	else{
		h = 10;
	}
}

Bullet::~Bullet(){
}

bool Bullet::isCollides(Player * human){
	if((human->getX() >= (x - 26 - w)) && (human->getX() <= (x + w))){
		if((human->getY() >= y - 26 - h) && (human->getY() <= (y + h))){
			valid = false;
			return true;
		}
	}
	return false;
}

bool Bullet::isCollides(Thing* ship){
	if((ship->getX() >= (x - 26 - w)) && (ship->getX() <= (x + w))){
		if((ship->getY() >= y - 26) && (ship->getY() <= (y))){
			valid = false;
			return true;
		}
	}
	return false;
}


int Bullet::getAttack(){
	return attack;
}
		
void Bullet::move(){
	y += vy;
	setY(y);
}

void Bullet::action(){
	// checks if it's still valid
	
	if(y < 0 || y > 605){
		valid = false;
	}
}

bool Bullet::isValid(){
	return valid;
}
