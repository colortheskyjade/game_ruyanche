#ifndef BLUE_H
#define BLUE_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;

/** Blue, inverted triangle, ship. */
class Blue : public Thing{
	public:
		/** Constructor takes in pixmaps for animation, initial coords, and MainWindow pointer */
		Blue(QPixmap*, QPixmap*, int, int, MainWindow*);
		~Blue();
		
		void move();
		/** Fires bullets randomly */
		void action();
		bool isValid();
		int getScore(){return 100;}
		
	private:
		int maxX, minX, count, attack, anim;
		MainWindow *m;
		QPixmap *p1, *p2;
		bool valid;
};

#endif
