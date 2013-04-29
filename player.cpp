#include "player.h"

Player::Player(QPixmap *pm, int nx, int ny, MainWindow * mw) : QGraphicsPixmapItem(*pm){
	lives = 3;
	p = pm;
	setPixmap(*p);
	x = nx;
	y = ny;
	h = 25;
	w = 25;
	setPos(x, y);
	m = mw;
	hp = 10;
	anim = 0;
	godly = false;
}

Player::~Player(){
}

void Player::move(int vx, int vy){
	x += vx;
	y += vy;
	if(y >= 570){
		y = 570;
	}
	else if(y <= 450){
		y = 450;
	}
	if(x <= 0){
		x = 0;
	}
	if(x >= 395){
		x= 395;
	}
	setPos(x, y);
}

void Player::doAttack(){
 	m->makePlayerBullet(x+14,y);
}

void Player::action(){
	if(invincible && !godly){
		if(!(anim % 30)){
			setVisible(false);
		}
		else if(anim % 30 == 14){
			setVisible(true);
		}
		anim++;
		if(anim == 299){
			setVisible(true);
			invincible = false;
			anim = 0;
		}
	}
	
 	if(hp <= 0){
 		lives--;
 	}
}

bool Player::isDead(){
	return !static_cast<bool>(lives);
}

void Player::gotHit(int attack){
	if(!invincible && !godly){
		hp -= attack;
	}
}

bool Player::isInvincible(){
	return invincible;
}

void Player::setInvincible(){
	invincible = true;
}

int Player::getHP(){
	return hp;
}

void Player::setHP(int hp_){
	hp = hp_;
}

int Player::getX(){
	return x;
}

int Player::getY(){
	return y;
}
