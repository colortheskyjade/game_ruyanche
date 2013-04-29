#ifndef PURPLE_H
#define PURPLE_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;
class Player;

/** Purple jellyfish-like ship. */
class Purple : public Thing{
	public:
		/** Constructor, takes in pictures, coordinates, and useful pointers. */
		Purple(QPixmap* p, int x, int y, MainWindow* mw, Player* pl);
		~Purple();
		
		/** Moves left and right */
		void move();
		/** Checks if the ship is valid */
		void action();
		/** Returns true if ship is valid for gameplay */
		bool isValid();
		/** Checks if the ship has collided with the player */
		void isCollides();
		int getScore(){	return 300;}
		
	private:
		int maxX, minX, count;
		bool valid; 
		MainWindow *m;
		Player* human;
		int state; //0 = normal, 1 = "dead", 2 = actually dead
};

#endif
