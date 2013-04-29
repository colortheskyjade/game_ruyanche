#ifndef RED_H
#define RED_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;
class Player;

class Red : public Thing{
	public:
		Red(QPixmap* p, QPixmap* p2_, QPixmap* p3_, int x, int y, MainWindow* mw, Player* pl = 0);
		~Red();
		
		void move();
		void action();
		bool isValid();
		void nextState(){state = 4;}
		int getScore(){	return score;}
		void gotHit(int);
		
	private:
		QPixmap *p1, *p2, *p3;
		int maxX, minX, count, attack, state, ani, bounce, targetX, score;
		MainWindow *m;
		Player* human;
		bool valid;
};

#endif
