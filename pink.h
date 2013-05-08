#ifndef PINK_H
#define PINK_H

#include "thing.h"
#include "mw.h"
#include <iostream>
#include <QPixmap>

class MainWindow;

/** Pink teleporting ship. */
class Pink : public Thing{
	public:
		/** Constructor takes in pixmaps for animation, initial coords, and MainWindow pointer */
		Pink(QPixmap*, int, int, MainWindow*);
		~Pink();
		
		void move();
		/** Fires bullets randomly */
		void action();
		bool isValid();
		int getScore(){return 400;}
		
	private:
		int maxX, minX, maxY, minY, count, attack;
		bool valid;
		MainWindow *m;
		QPixmap *p1;
};

#endif
