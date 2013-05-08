#include "yellow.h"

Yellow::Yellow(QPixmap* p, int x, int y, MainWindow* mw) : Thing(p, x, y, 30, 30){
	hp = 10;
	valid = true;
	p1 = p;
	m = mw;
	count = 0;
}

Yellow::~Yellow(){
}

bool Yellow::isValid(){
	return valid;
}
		
void Yellow::move(){
	//i don't move
}

void Yellow::action(){
	if(count == 15){
		if(!(rand()%5)){
			// randomly fire two bullets
			m->makeYellowBullet(x+14,y+35);
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
