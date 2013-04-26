#include "gscene.h"

GScene::GScene() : QGraphicsScene(){}

void GScene::keyPressEvent( QKeyEvent *e ) {
	switch ( e->key() ) {
		case Qt::Key_Left :
			std::cout << "L" << std::endl;
			break;
		case Qt::Key_Right :
			std::cout << "R" << std::endl;
			break;
		case Qt::Key_Up :
			std::cout << "U" << std::endl;
			break;
		case Qt::Key_Down :
			std::cout << "D" << std::endl;
			break;
		case Qt::Key_Space :
			std::cout << "S" << std::endl;
			break;
	}
}
