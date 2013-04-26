#ifndef GSCENE_H
#define GSCENE_H

#include <iostream>
#include <QGraphicsScene>
#include <QKeyEvent>

class GScene : public QGraphicsScene{
	public:
		GScene();
		void keyPressEvent(QKeyEvent *e);
};

#endif
