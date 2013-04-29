#include "red.h"

Red::Red(QPixmap* p, QPixmap* p2_, QPixmap* p3_, int x, int y, MainWindow* mw, Player* pl) : Thing(p, x, y, 25, 25){
	score = 1000;
	bounce = 0;
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
	}
	if(!state){
		if(!(count % 2)){

			x += vx;
		
			if(x <= minX){vx = vx * -1; x += vx; bounce++;}
			else if(x >= maxX){vx = vx * -1; x += vx;}
		
			setX(x);
		}
	}
	else if(state == 1){
		x = -30;
		y = 380;
		setX(-30);
		setY(380);
		targetX = human->getX();
		state = 2;
	}
	else if(state == 2){
		if(!(count % 2)){
			x += 5;
			setX(x);
			if(x > targetX){
				state = 3;
			}
		}
	}
	else if(state == 3){
		m->fireBeam(x,y+30);
	}
	else if(state == 4){
		targetX = -30;
		state = 5;
	}
	else if(state == 5){
		if(!(count % 2)){
			x += -5;
			setX(x);
			if(x <= -30){
				valid = false;
				score = 0;
			}
		}
	}
}

void Red::gotHit(int number){
	if(state < 3)
		hp -= number;
}

void Red::action(){
	if(count == 20){
		if(!(rand()%15) && state == 0){
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
	if(bounce == 2){
		minX = -30;
	}
	if(bounce == 3){
		state = 1;
		bounce++;
	}
}
