#ifndef BLUE_H
#define BLUE_H

#include "thing.h"
#include <QPixmap>

class Bullet : public Thing{
	public:
		Bullet(QPixmap* p, int x, int y, bool up, bool red, int attack);
		~Bullet();
		
		void move();
		void action();
		
	private:
		bool up;
		bool red;
		int attack;
};

#endif
