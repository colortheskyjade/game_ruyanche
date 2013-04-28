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
		void setHP(int);
		void setInvincible();
		
		int getLives(){return lives;}
		void addLife(){lives++;}
		
		int getHP();
		int getX();
		int getY();
		
	protected:
		int x, y, h , w, anim, hp, lives;
		QPixmap *p;
		bool invincible, godly;
		MainWindow *m;
};

#endif
