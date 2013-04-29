#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "mw.h"

class MainWindow;

/** The player-controlled ship in the game. */
class Player : public QGraphicsPixmapItem {
	public:
		/** Constructor takes in image, initial coords, and MainWindow pointer */
		Player(QPixmap *pm, int nx, int ny, MainWindow * mw);
		~Player();
		
		/** Move the player
			* @param vx Horizontal velocity
			* @param vy Vertical velocity
			*/
		void move(int vx, int vy);
		/** Adjusts the player's life-count as necessary. */
		void action();
		/** Returns true if the player is out of lives */
		bool isDead();
		/** Deducts the HP by the attack amount */
		void gotHit(int attack);
		/** Returns true if the player is invincible */
		bool isInvincible();
		/** Fires a bullet */
		void doAttack();
		/** Sets HP to the given integer */
		void setHP(int);
		/** Makes the player invincible */
		void setInvincible();
		/** Makes the player permanently invincible */
		void setGodly(){godly = true;}
		
		/** Returns the number of lives */
		int getLives(){return lives;}
		/** Adds a life to the player */
		void addLife(){lives++;}
		
		/** Returns the current amount of HP */
		int getHP();
		/** Returns the current x-coord */
		int getX();
		/** Returns the current y-coord */
		int getY();
		
	protected:
		int x, y, h , w, anim, hp, lives;
		QPixmap *p;
		bool invincible, godly;
		MainWindow *m;
};

#endif
