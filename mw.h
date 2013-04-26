#ifndef MW
#define MW

// Qt Things
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRadioButton>
#include <QListView>
#include <QtGui>
#include <QFormLayout>

// C++ Things
#include <cstdlib>
#include <iostream>

// Others
#include "thing.h"
#include "blue.h"

#define W_X 600
#define W_Y 600

class MainWindow : public QMainWindow{
	Q_OBJECT
	
	public:
		MainWindow();
//		~MainWindow();
		
		void show();
	
	public slots:
		void handleTimer();
	protected:
//		void keyPressEvent(QKeyEvent *e);
	
	private:
		QTimer * timer;
		QGraphicsScene *gameScene;
		QGraphicsView *gameView;
		QPixmap *redpic, *bluepic, *greenpic, *purplepic, *bulletpic, *beampic;
		
		std::vector<Thing*> enemies;
		std::vector<Thing*> bullets;
		Thing * tractorB;
		
		Thing* player;
		
		int gameSpeed;
};

#endif
