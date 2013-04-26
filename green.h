#ifndef GREEN_H
#define GREEN_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;

class Green : public Thing{
	public:
		Green(QPixmap* p, int x, int y, MainWindow* mw);
		~Green();
		
		void move();
		void action();
		
	private:
		int maxX;
		int minX;
		int maxY;
		int minY;
		bool ccw;
		int count;
		int hp;
		int attack;
		MainWindow *m;
};

#endif
