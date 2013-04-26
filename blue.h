#ifndef BLUE_H
#define BLUE_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;

class Blue : public Thing{
	public:
		Blue(QPixmap*, QPixmap*, int, int, MainWindow*);
		~Blue();
		
		void move();
		void action();
		bool isValid();
		
	private:
		int maxX, minX, count, attack, anim;
		MainWindow *m;
		QPixmap *p1, *p2;
		bool valid;
};

#endif
