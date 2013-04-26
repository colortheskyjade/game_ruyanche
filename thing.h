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
		virtual bool isValid() = 0;
		
		virtual void gotHit(int);
		
		int getX();
		int getY();
		
	protected:
		int x, y, vx, vy, h, w, hp;
		QPixmap *pixMap;
};

#endif
