#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Thing : public QGraphicsPixmapItem {
	public:
		Thing(QPixmap *pm, int nx, int ny, int nh, int nw);
		~Thing();
		
		virtual void move() = 0;
		virtual void action() = 0;
		
	protected:
		int x;
		int y;
		int vx;
		int vy;
		int h;
		int w;
		QPixmap *pixMap;
};

#endif
