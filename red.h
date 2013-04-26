#ifndef RED_H
#define RED_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;
class Player;

class Rede : public Thing{
	public:
		Red(QPixmap* p, QPixmap* p2_, QPixmap* p3_, int x, int y, MainWindow* mw, Player* pl = 0);
		~Red();
		
		void move();
		void action();
		
	private:
		QPixmap* p2, p3;
		int maxX;
		int minX;
		int count;
		int hp;
		int attack;
		MainWindow *m;
		Player* human;
		int state; //0 = normal, 1 = "dead", 2 = actually dead
};

#endif
