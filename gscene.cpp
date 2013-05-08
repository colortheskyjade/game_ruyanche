#include "gscene.h"

GScene::GScene(MainWindow *mw) : QGraphicsScene(), m(mw){}

void GScene::keyPressEvent( QKeyEvent *e ) {
	int v = 5;
	// move in a different direction depending on the keypress
	// use esc to pause/unpause
	// use space to shoot
	switch ( e->key() ) {
		case Qt::Key_Left :
			m->moveP(-1 * v, 0);
			break;
		case Qt::Key_Right :
			m->moveP(v, 0);
			break;
		case Qt::Key_Up :
			m->moveP(0, -1 * v);
			break;
		case Qt::Key_Down :
			m->moveP(0, v);
			break;
		case Qt::Key_Space :
			m->shootP();
			break;
		case Qt::Key_Escape :
			if(m->isPaused()){m->resumeGame();}
			else{m->pauseGame();}
			break;
	}
	// there exists a keyReleaseEvent
	// do a lot of bools
	// and uh... yeah have to handleTimer this gdi thing too 
}
