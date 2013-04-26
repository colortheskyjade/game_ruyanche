#include "thing.h"

Thing::Thing(QPixmap* p, int nx, int ny, int nh, int nw) : QGraphicsPixmapItem(*p) {
	pixMap = p;
	setPixmap(*p);
	x = nx;
	y = ny;
	h = nh;
	w = nw;
	setPos(x, y);
}

Thing::~Thing(){}
