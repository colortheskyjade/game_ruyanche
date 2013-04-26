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
#include <deque>
#include <sstream>

// Others
#include "thing.h"
#include "blue.h"
#include "bullet.h"
#include "green.h"
#include "purple.h"
#include "red.h"
#include "player.h"
#include "gscene.h"

#define W_X 600
#define W_Y 600

class MainWindow : public QMainWindow{
	Q_OBJECT
	
	public:
		MainWindow();
//		~MainWindow();
		
		void show();
		
		// Game States
		void pauseGame();
		void resumeGame();
		bool isPaused();
		
		// Make bullets
		void makeBlueBullet(int x, int y);
		void makeGreenBullet(int x, int y);
		void makeBigBullet(int x, int y);
		void makePlayerBullet(int x, int y);
		
		// Make beam
		
		// Player queued actions
		void moveP(int, int);
		void shootP();
		
		// Collision handling
	
	public slots:
		void handleTimer();
	
	private:
		QTimer * timer;
		QGraphicsScene *gameScene;
		QGraphicsView *gameView;
		QPixmap *ab1, *ab2, *ag1, *ag2, *apl, *ap, *ar1, *ar2, *ar3, *pbullet, *bbullet, *gbullet, *widebulletpic, *heartpic;
		QLabel * hpL;
		int gameSpeed, attack;
		bool paused;
		
		std::vector<Thing*> enemies;
		std::vector<Thing*> ebullets;
		std::vector<Thing*> pbullets;
		Thing * tractorB;
		
		Player* human;
		int maxhp;
		
		//queued actions
		int pvx, pvy;
		bool pattack;
};

#endif
