#ifndef BLUE_H
#define BLUE_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;

class Blue : public Thing{
	public:
		Blue(QPixmap* p, int x, int y, MainWindow* m);
		~Blue();
		
		void move();
		void action();
		
	private:
		int maxX;
		int minX;
		int count;
		int hp;
		int attack;
		MainWindow *m;
};

#endif
