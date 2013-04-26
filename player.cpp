#include "player.h"

Player::Player(QPixmap *pm, int nx, int ny, MainWindow * mw) : QGraphicsPixmapItem(*pm){
	p = pm;
	setPixmap(*p);
	x = nx;
	y = ny;
	h = 25;
	w = 25;
	setPos(x, y);
	m = mw;
}

Player::~Player(){
}

void Player::move(int vx, int vy){
	x += vx;
	y += vy;
	setPos(x, y);
}

void Player::doAttack(){
 	m->makePlayerBullet(x+14,y);
}

void Player::action(){
}

bool Player::isDead(){
	return (hp <= 0);
}

void Player::gotHit(int attack){
	hp -= attack;
}

bool Player::isInvincible(){
	return invincible;
}
