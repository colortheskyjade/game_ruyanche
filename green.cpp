#include "green.h"

Green::Green(QPixmap* p, int x, int y, MainWindow* mw) : Thing(p, x, y, 25, 25){
	m = mw;
	count = 0;
	
	vy = 0;
	vx = 1;
	ccw = false;
	if(rand() % 2 == 1){
		vx = 0;
		vy = 1;
		ccw = true;
		std::cout << "ME" << std::endl;
	}
	
	// set boundaries
	minX = x;
	maxX = x + 50;
	minY = y;
	maxY = y + 50;
	
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
		
void Green::move(){
	if(!(count % 5)){
		x += vx;
		y += vy;
		
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
	if(count == 20){
		if(!(rand()%20)){
			m->makeBullet(x+12,y+35,false,attack);
			m->makeBullet(x+13,y+25,false,attack);
		}
		count = 0;
	}
	else{
		count++;
	}
}
