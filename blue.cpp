#include "blue.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

Blue::Blue(QPixmap* p, QPixmap* p2_, int x, int y, MainWindow* mw) : Thing(p, x, y, 25, 25){
	hp = 2;
	valid = true;
	p1 = p;
	p2 = p2_;
	m = mw;
	vy = 0;
	anim = rand() % 14;
	vx = 2 * pow(-1, rand() % 2);

	count = 0;
	
	// set boundaries
	if(x < 176){
		minX = 10;
		maxX =  175;
	}
	else{
		minX = 205;
		maxX = 400;
	}
	
}

Blue::~Blue(){
}

bool Blue::isValid(){
	return valid;
}

void Blue::move(){
	if(!(count % 5)){
		if(anim < 7){
			setPixmap(*p1);
			anim++;
		}
		else {
			anim++;
			anim = anim % 14;
			setPixmap(*p2);
		}

		
		x += vx;
		
		if(x < minX){vx = vx * -1; x += vx;}
		else if(x > maxX){vx = vx * -1; x += vx;}
		
		setX(x);
	}
}

void Blue::action(){
	if(count == 15){
		if(!(rand()%15)){
			m->makeBlueBullet(x+14,y+25);
		}
		count = 0;
	}
	else{
		count++;
	}
}
