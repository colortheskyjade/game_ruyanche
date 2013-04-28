#ifndef BULLET_H
#define BULLET_H

#include "thing.h"
#include "player.h"
#include <QPixmap>
#include <cmath>
#include <cstdlib>

class Player;

class Bullet : public Thing{
	public:
		Bullet(QPixmap* p, int x, int y, bool up, int attack, bool red = 0, bool heart = 0);
		~Bullet();
		
		void move();
		void action();
		bool isValid();
		bool isCollides(Player*);
		bool isCollides(Thing*);
		int getAttack();
		int getScore(){if(heart) return 500; return 0;}
		
	private:
		bool up, red, valid, heart;
		int attack;
};

#endif
