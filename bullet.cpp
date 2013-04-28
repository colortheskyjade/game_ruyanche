#include "bullet.h"

Bullet::Bullet(QPixmap* p, int x, int y, bool up, int attack, bool red, bool heart) : Thing(p, x, y, 0 , 0), heart(heart), attack(attack){
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
	if(collidesWithItem(human)){
			valid = false;
			return true;
	}
	return false;
}

bool Bullet::isCollides(Thing* ship){
	if(collidesWithItem(ship)){
			valid = false;
			return true;
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
