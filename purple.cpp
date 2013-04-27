#include "purple.h"

Purple::Purple(QPixmap* p, int x, int y, MainWindow* mw, Player* pl) : Thing(p, x, y, 25, 25){
	hp = 6;
	valid = true;
	m = mw;
	human = pl;
	state = 0;
	vy = 0;
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

Purple::~Purple(){
}

void Purple::isCollides(){
	if((human->getX() >= (x - 60)) && (human->getX() <= (x + 30))){
		if((human->getY() >= y - 60) && (human->getY() <= (y + 30))){
			valid = false;
			human->gotHit(1000);
		}
	}
}

bool Purple::isValid(){
	return valid;
}

void Purple::move(){
	if(!state){
		if(!(count % 5)){
			x += vx;
		
			if(x < minX){vx = vx * -1; x = minX;}
			else if(x > maxX){vx = vx * -1; x = maxX;}
		
			setX(x);
		}
	}
	else if(state == 1){
		if(vx){vx = 0;}
		if(!vy){vy = 2;}
		if(!(count % 1)){
			y += vy;
			setY(y);
		}
	}
}

void Purple::action(){
	purple = true;
	count++;
	
	// check valid
	if(hp <= 0){
		state = 1;
	}
	if(y > 600){
		valid = false;
	}
}
