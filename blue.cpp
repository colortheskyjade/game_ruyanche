#include "blue.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

Blue::Blue(QPixmap* p, int x, int y, MainWindow* mw) : Thing(p, x, y, 25, 25){
	m = mw;
	vy = 0;
	vx = 2 * pow(-1, rand() % 2);

	count = 0;
	
	// set boundaries
	int temp = rand() % 100;
	minX = x - temp;
	maxX = x + 100 - temp;
	
	if(minX < 0){
		minX = 0;
	}
	if(maxX > 400){
		maxX = 400;
	}
}

Blue::~Blue(){
}

void Blue::move(){
	if(!(count % 5)){
		x += vx;
		
		if(x < minX){vx = vx * -1; x += vx;}
		else if(x > maxX){vx = vx * -1; x += vx;}
		
		setX(x);
	}
}

void Blue::action(){
	if(count == 20){
		if(!(rand()%15)){
			m->makeBullet(x+12,y+25,false,attack);
		}
		count = 0;
	}
	else{
		count++;
	}
}
