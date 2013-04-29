#ifndef GREEN_H
#define GREEN_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;

/** Green, angry-looking ship */
class Green : public Thing{
	public:
		/** Constructor, takes in pixmaps for animation, position, and MainWindow pointer */
		Green(QPixmap*, QPixmap*, int, int, MainWindow*);
		~Green();
		
		void move();
		/** Fires bullets as necessary */
		void action();
		bool isValid();
		int getScore(){return 150;}
		
	private:
		int maxX, minX, maxY, minY, count, attack, anim;
		bool ccw, valid;
		MainWindow *m;
		QPixmap *p1, *p2;
};

#endif
