#include "red.h"

Red::Red(QPixmap* p, QPixmap* p2_, QPixmap* p3_, int x, int y, MainWindow* mw, Player* pl) : Thing(p, x, y, 25, 25){
	p2 = p2_;
	p3 = p3_;
	m = mw;
	human = pl;
	state = 0;
	vy = 0;
	vx = 5 * pow(-1, rand() % 2);

	count = 0;
	
	// set boundaries
	minX = 25;
	maxX = 375;
}

Red::~Red(){
}

void Red::move(){
	if(!state){
		if(!(count % 5)){
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
	if(count == 60){
		if(!(rand()%15)){
			m->makeBigBullet(x+12,y+25,attack);
		}
		count = 0;
	}
	else{
		count++;
	}
}
