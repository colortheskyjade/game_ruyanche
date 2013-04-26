#ifndef PURPLE_H
#define PURPLE_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;
class Player;

class Purple : public Thing{
	public:
		Purple(QPixmap* p, int x, int y, MainWindow* mw, Player* pl = 0);
		~Purple();
		
		void move();
		void action();
		
	private:
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
