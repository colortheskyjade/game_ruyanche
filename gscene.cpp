#include "gscene.h"

GScene::GScene(MainWindow *mw) : QGraphicsScene(), m(mw){
	left = false;
	right = false;
	up = false;
	down = false;
	space = false;
}

void GScene::keyPressEvent( QKeyEvent *e ) {
	// move in a different direction depending on the keypress
	// use esc to pause/unpause
	// use space to shoot
	switch ( e->key() ) {
		case Qt::Key_Left :
			left = true;
			break;
		case Qt::Key_Right :
			right = true;
			break;
		case Qt::Key_Up :
			up = true;
			break;
		case Qt::Key_Down :
			down = true;
			break;
		case Qt::Key_Space :
			space = true;
			break;
		case Qt::Key_Escape :
			m->pauseGame();
			break;
	}
}

void GScene::keyReleaseEvent( QKeyEvent *e ) {
	// move in a different direction depending on the keypress
	// use esc to pause/unpause
	// use space to shoot
	switch ( e->key() ) {
		case Qt::Key_Left :
			left = false;
			break;
		case Qt::Key_Right :
			right = false;
			break;
		case Qt::Key_Up :
			up = false;
			break;
		case Qt::Key_Down :
			down = false;
			break;
		case Qt::Key_Space :
			space = false;
			break;
	}
}

void GScene::action(){
	int v = 2;
	if(left){
		m->moveP(-1 * v, 0);
	}
	if(right){
		m->moveP(v , 0);
	}
	if(up){
		m->moveP(0, -1 * v);
	}
	if(down){
		m->moveP(0, v);
	}
	if(space){
		m->shootP();
	}
}
