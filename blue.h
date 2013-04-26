#ifndef BLUE_H
#define BLUE_H

#include "thing.h"
#include <QPixmap>

class Blue : public Thing{
	public:
		Blue(QPixmap* p, int x, int y);
		~Blue();
		
		void move();
		void action();
		
	private:
		int maxX;
		int minX;
		int count;
		int hp;
		int attack;
};

#endif
