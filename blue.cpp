#include "blue.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

Blue::Blue(QPixmap* p, QPixmap* p2_, int x, int y, MainWindow* mw) : Thing(p, x, y, 30, 30){
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
	if(x <= 160){
		minX = 10;
		maxX =  160;
	}
	else{
		minX = 210;
		maxX = 390;
	}
	
}

Blue::~Blue(){
}

bool Blue::isValid(){
	return valid;
}

void Blue::move(){
	if(!(count % 5)){
		// animate the ship
		if(anim % 14 == 6){
			setPixmap(*p1);
		}
		else if(anim % 14 == 0){
			anim = 0;
			setPixmap(*p2);
		}
		anim++;

		x += vx;
		
		// bounce once it gets to the boundaries
		if(x < minX){vx = vx * -1; x = minX;}
		else if(x > maxX){vx = vx * -1; x = maxX;}
		
		setX(x);
	}
}

void Blue::action(){
	// random shooting
	if(count == 15){
		if(!(rand()%10)){
			m->makeBlueBullet(x+15,y+30);
		}
		count = 0;
	}
	else{
		count++;
	}
	
	// check valid
	if(hp <= 0){
		valid = false;
	}
}
