#ifndef YELLOW_H
#define YELLOW_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;

/** Yellow, brick-like, ship. */
class Yellow : public Thing{
	public:
		/** Constructor takes in pixmaps for animation, initial coords, and MainWindow pointer */
		Yellow(QPixmap*, int, int, MainWindow*);
		~Yellow();
		
		/** This ship doesn't move */
		void move();
		/** Fires bullets randomly */
		void action();
		bool isValid();
		int getScore(){return 50;}
		
	private:
		int count, attack;
		bool valid;
		MainWindow *m;
		QPixmap *p1;
};

#endif
