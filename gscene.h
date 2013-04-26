#ifndef GSCENE_H
#define GSCENE_H

#include <iostream>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "mw.h"

class MainWindow;

class GScene : public QGraphicsScene{
	public:
		GScene(MainWindow*);
		void keyPressEvent(QKeyEvent *e);
	private:
		MainWindow *m;
};

#endif
