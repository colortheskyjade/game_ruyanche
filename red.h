#ifndef RED_H
#define RED_H

#include "thing.h"
#include "mw.h"
#include <QPixmap>

class MainWindow;
class Player;

/** Red/mothership class. */
class Red : public Thing{
	public:
		/** Constrcutor
			* @param p/p2/p3 The various images used for the animation.
			* @param x/y Coordinates of spawn
			*/
		Red(QPixmap* p, QPixmap* p2_, QPixmap* p3_, int x, int y, MainWindow* mw, Player* pl);
		~Red();
		
		/** Moves the ship throughout its various states. */
		void move();
		/** Sets the states as necessary and randomly fires. */
		void action();
		bool isValid();
		/** Progresses state after the mothership has fired the beam. */
		void nextState(){state = 4;}
		/** Get the value of the mothership for scoring. */
		int getScore(){	return score;}
		/** Deducts life based on the attack of the bullet.
			* @param attack Attack of the bullet that hit it.
			*/ 
		void gotHit(int attack);
		
	private:
		QPixmap *p1, *p2, *p3;
		int maxX, minX, count, attack, state, ani, bounce, targetX, score;
		MainWindow *m;
		Player* human;
		bool valid;
};

#endif
