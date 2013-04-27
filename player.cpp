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
	hp = 10;
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
