#ifndef BULLET_H
#define BULLET_H

#include "thing.h"
#include <QPixmap>

class Bullet : public Thing{
	public:
		Bullet(QPixmap* p, int x, int y, bool up, int attack, bool red = 0, bool heart = 0);
		~Bullet();
		
		void move();
		void action();
		
	private:
		bool up;
		bool red;
		int attack;
};

#endif
