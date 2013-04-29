#ifndef BULLET_H
#define BULLET_H

#include "thing.h"
#include "player.h"
#include <QPixmap>
#include <cmath>
#include <cstdlib>

class Player;

/** Bullet/projectiles in the game */
class Bullet : public Thing{
	public:
		/** Default constructor, takes in image, coords, and attributes to describe the bullet necessary */
		Bullet(QPixmap* p, int x, int y, bool up, int attack, bool red = 0, bool heart = 0, bool beam = 0);
		~Bullet();
		
		void move();
		/** Invalidates the bullet once it goes offscreen */
		void action();
		bool isValid();
		/** Checks for collisions with the Player */
		bool isCollides(Player*);
		/** Checks for collisions with other Things */
		bool isCollides(Thing*);
		/** Gets the attack value of the bullet (how much damage it does) */
		int getAttack();
		int getScore(){if(heart) return 500; return 0;}
		
	private:
		bool up, red, valid, heart, beam;
		int attack;
};

#endif
