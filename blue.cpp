#include "blue.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

Blue::Blue(QPixmap* p, int x, int y, MainWindow* mw) : Thing(p, x, y, 25, 25){
	m = mw;
	vy = 0;
	vx = 2 * pow(-1, rand() % 2);
	std::cout << vx << std::endl;

	count = 0;
	
	// set boundaries
	int temp = rand() % 100;
	minX = x - temp;
	maxX = x + 100 - temp;
	std::cout << minX << std::endl;
	std::cout << maxX << std::endl;
}

Blue::~Blue(){
}

void Blue::move(){
	if(count == 5){
		count = 0;
		x += vx;
		
		if(x < minX){vx = vx * -1; x += vx;}
		else if(x > maxX){vx = vx * -1; x += vx;}
		
		setX(x);
	}
	else{
		count++;
	}
}

void Blue::action(){
	
}
