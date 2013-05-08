#include "pink.h"

Pink::Pink(QPixmap* p, int x, int y, MainWindow* mw) : Thing(p, x, y, 30, 30){
	hp = 4;
	valid = true;
	p1 = p;
	m = mw;
	count = 0;
	
	// set boundaries
	minX = 30;
	maxX = 400;
	minY = 50;
	maxY = 320;
}

Pink::~Pink(){
}

bool Pink::isValid(){
	return valid;
}
		
void Pink::move(){
	if(!(count % 15000)){
		if(!(rand() % 200)){
			x += rand() % 100 * pow(-1, rand() % 2);
			y += rand() % 100 * pow(-1, rand() % 2);
			if(x <= minX){x = minX;}
			else if(x >= maxX){x = maxX;}
			if(y <= minY){y = minY;}
			else if(y >= maxY){y = maxY;}
			setPos(x,y);
			count = 0;
		}
	}
	else{
		count++;
	}
}

void Pink::action(){
	if(count % 30 == 0){
		if(!(rand()%75)){
			// randomly fire two bullets
			m->makePinkBullet(x+14,y+35);
		}
	}
	
	// check valid
	if(hp <= 0){
		valid = false;
	}
}
