#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

/** Abstract class for Things in the game.
	*/
class Thing : public QGraphicsPixmapItem {
	public:
		Thing(QPixmap *pm, int nx, int ny, int nh, int nw);
		~Thing();
		
		/** Moves the ships */
		virtual void move() = 0;
		virtual void action() = 0;
		/** Returns true if the ship is valid in gameplay. */
		virtual bool isValid() = 0;
		
		/** Deducts the necessary points from the ship's hp */
		virtual void gotHit(int);
		/** Get the value of the thing for scoring. */
		virtual int getScore(){return 0;}
		
		/** Returns x coordinate of object */
		int getX();
		/** Returns y coordinate of object */
		int getY();
		
		/** Returns true if the ship is purple. */
		bool isPurple(){return purple;}
		
	protected:
		int x, y, vx, vy, h, w, hp;
		QPixmap *pixMap;
		bool purple;
};

#endif
