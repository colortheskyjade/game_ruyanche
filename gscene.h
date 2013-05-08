#ifndef GSCENE_H
#define GSCENE_H

#include <iostream>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "mw.h"

class MainWindow;

/** Inherited from QGraphicsScene to implement keyboard functions. */
class GScene : public QGraphicsScene{
	public:
		/** Constructor takes in MainWindow pointer to perform functions. */
		GScene(MainWindow*);
		/** Responds to the left, right, up, down arrow keys, space bar, and esc key as necessary */
		void keyPressEvent(QKeyEvent *e);
		void keyReleaseEvent(QKeyEvent *e);
		void action();
	private:
		MainWindow *m;
		bool left, right, up, down, space;
};

#endif
