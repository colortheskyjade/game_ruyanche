#include "bullet.h"

Bullet::Bullet(QPixmap* p, int x, int y, bool up, int attack, bool red, bool heart) : Thing(p, x, y, 0 , 0){
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
		
void Bullet::move(){
	y += vy;
	setY(y);
}

void Bullet::action(){

}
