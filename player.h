#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "mw.h"

class MainWindow;

class Player : public QGraphicsPixmapItem {
	public:
		Player(QPixmap *pm, int nx, int ny, MainWindow * mw);
		~Player();
		
		void move(int vx, int vy);
		void action();
		bool isDead();
		void gotHit(int attack);
		bool isInvincible();
		void doAttack();
		
	protected:
		int x;
		int y;
		int h;
		int w;
		QPixmap *p;
		int hp;
		bool invincible;
		MainWindow *m;
		int attack;
};

#endif
