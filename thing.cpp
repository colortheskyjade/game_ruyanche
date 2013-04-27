#include "thing.h"

Thing::Thing(QPixmap* p, int nx, int ny, int nh, int nw) : QGraphicsPixmapItem(*p) {
	pixMap = p;
	setPixmap(*p);
	x = nx;
	y = ny;
	h = nh;
	w = nw;
	setPos(x, y);
	purple = false;
}

Thing::~Thing(){}

int Thing::getX(){
	return x;
}

int Thing::getY(){
	return y;
}

void Thing::gotHit(int number){
	hp -= number;
}
