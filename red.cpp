#include "red.h"

Red::Red(QPixmap* p, QPixmap* p2_, QPixmap* p3_, int x, int y, MainWindow* mw, Player* pl) : Thing(p, x, y, 25, 25){
	hp = 4;
	valid = true;
	p1 = p;
	p2 = p2_;
	p3 = p3_;
	m = mw;
	human = pl;
	state = 0;
	ani = 0;
	vy = 0;
	vx = 5 * pow(-1, rand() % 2);

	count = 0;
	
	// set boundaries
	minX = 10;
	maxX = 390;
}

Red::~Red(){
}

bool Red::isValid(){
	return valid;
}

void Red::move(){
	if(!state){
		if(!(count % 2)){
			if(ani < 10){
				setPixmap(*p1);
				ani++;
			}
			else if(ani < 20){
				setPixmap(*p2);
				ani++;
			}
			else{
				setPixmap(*p3);
				ani++;
				ani = ani % 30;
			}
			x += vx;
		
			if(x <= minX){vx = vx * -1; x += vx;}
			else if(x >= maxX){vx = vx * -1; x += vx;}
		
			setX(x);
		}
	}
	else if(state == 1){
		//
	}
}

void Red::action(){
	if(count == 20){
		if(!(rand()%15)){
			m->makeBigBullet(x+15,y+30);
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
