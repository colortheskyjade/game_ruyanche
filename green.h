#ifndef GREEN_H
#define GREEN_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;

class Green : public Thing{
	public:
		Green(QPixmap*, QPixmap*, int, int, MainWindow*);
		~Green();
		
		void move();
		void action();
		bool isValid();
		
	private:
		int maxX, minX, maxY, minY, count, attack, anim;
		bool ccw, valid;
		MainWindow *m;
		QPixmap *p1, *p2;
};

#endif
