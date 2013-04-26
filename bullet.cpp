#include "bullet.h"

Bullet::Bullet(QPixmap* p, int x, int y, bool up, bool red, int attack) : Thing(p, x, y, 0 , 0){
	
}

Bullet::~Bullet(){
}
		
void move();
void action();
