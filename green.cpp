#include "green.h"

Green::Green(QPixmap* p, QPixmap* p2_, int x, int y, MainWindow* mw) : Thing(p2_, x, y, 25, 25){
	hp = 6;
	valid = true;
	p1 = p;
	p2 = p2_;
	m = mw;
	count = 0;
	anim = rand() % 10;
	
	vy = 0;
	vx = 1;
	ccw = false;
	if(rand() % 2 == 1){
		// half the time it will go counterclockwise
		vx = 0;
		vy = 1;
		ccw = true;
	}
	
	// set boundaries
	minX = x;
	maxX = x + 50;
	minY = y;
	maxY = y + 50;
	
	// if the boundaries go out of bounds, fix them
	if(maxX > 400){
		maxX = 400;
		minX = 350;
	}
	if(minY < 100){
		minY = 100; maxY = 150;
	}
	if(maxY > 350){
		minY = 300; maxY = 350;
	}
}

Green::~Green(){
}

bool Green::isValid(){
	return valid;
}
		
void Green::move(){
	if(!(count % 5)){
// took out animation because it was running too slow
//		if(anim < 5){
//			setPixmap(*p1);
//			anim++;
//		}
//		else {
//			anim++;
//			anim = anim % 10;
//			setPixmap(*p2);
//		}

		x += vx;
		y += vy;
		// ccw and cw movements are slightly off of each other, but turn depending on what corner you're in
		if(!ccw){
			if(x <= minX && y <= minY){
				vy = 0;
				vx = 1;
				x = minX;
				y = minY;
			}
			else if(x >= maxX && y <= minY){
				vy = 1;
				vx = 0;
				x = maxX;
				y = minY;
			}
			else if(x >= maxX && y >= maxY){
				vy = 0;
				vx = -1;
				x = maxX;
				y = maxY;
			}
			else if(x <= minX && y >= maxY){
				vy = -1;
				vx = 0;
				x = minX;
				y = maxY;
			}
		}
		else{
			if(x <= minX && y <= minY){
				vy = 1;
				vx = 0;
				x = minX;
				y = minY;
			}
			else if(x >= maxX && y <= minY){
				vy = 0;
				vx = -1;
				x = maxX;
				y = minY;
			}
			else if(x >= maxX && y >= maxY){
				vy = -1;
				vx = 0;
				x = maxX;
				y = maxY;
			}
			else if(x <= minX && y >= maxY){
				vy = 0;
				vx = 1;
				x = minX;
				y = maxY;
			}
		}
		
		setPos(x,y);
	}
}

void Green::action(){
	if(count == 15){
		if(!(rand()%15)){
			// randomly fire two bullets
			m->makeGreenBullet(x+14,y+35);
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
