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
#include <fstream>
#include <algorithm>

// Others
#include "thing.h"
#include "blue.h"
#include "bullet.h"
#include "green.h"
#include "purple.h"
#include "red.h"
#include "player.h"
#include "gscene.h"
#include "pink.h"
#include "yellow.h"

#define W_X 600
#define W_Y 600

/** Holds the entire game and implements gameplay */
class MainWindow : public QMainWindow{
	Q_OBJECT
	
	public:
		/** Constructor initializes most game components and creates all widgets on screen. Also loads all images and connects all timers and buttons with the appropriate slot. */
		MainWindow();
		
		/** Shows the mainView of the application */
		void show();
		
		// Game States
		/** Starts a new level
			* @param l Level number
			*/
		void newLevel(int l);
		/** Ends the level, starting the short pause between levels. */
		void endLevel();
		/** Ends the game. Deletes all the player data and displays the score. */
		void endGame();
		/** Resumes game from pause */
		void resumeGame();
		/** Returns true if game is paused */
		bool isPaused();
		
		// Make bullets
		/** Make the bullet for the Blue ship */
		void makeBlueBullet(int x, int y);
		/** Make the bullet for the Green ship */
		void makeGreenBullet(int x, int y);
		/** Make the bullet for the Red ship */
		void makeBigBullet(int x, int y);
		/** Make the bullet for the Pink ship */
		void makePinkBullet(int x, int y);
		/** Make the bullet for the Yellow ship */
		void makeYellowBullet(int x, int y);
		/** Make the bullet for the Player */
		void makePlayerBullet(int x, int y);
		/** Fires the beam for the Red ship */
		void fireBeam(int, int);

		// Player queued actions
		/** Queues up the player's move in the specified (x,y) direction */
		void moveP(int, int);
		/** Queues up the player's shot */
		void shootP();
		
	public slots:
		/** Moves all of the items, checks for collisions, and updates the various widgets of the game. Also deletes items when they become unecessary. */
		void handleTimer();
		/** Starts the next level of the game */
		void nextLevel();
		/** Starts the game, creates the player and initializes the rest of the variables */
		void startGame();
		/** Pauses the game */
		void pauseGame();
		/** Restarts the game. Ends the game and immediately starts a new one. */
		void restartGame(){endGame(); startGame();}
		/** Quits the application. */
		void quitGame(){endGame(); QApplication::quit();}
	
	private:
		QTimer * timer, *timer2;
		QGraphicsScene *gameScene, *mainScene;
		QGraphicsView *gameView, *mainView;
		QPixmap *ab1, *ab2, *ag1, *ag2, *apl, *ap, *ar1, *ar2, *ar3, *pbullet, *bbullet, *gbullet, *widebulletpic, *heartpic, *rainbow, *bg1, *bg2, *bg3, *ppbullet, *ybullet, *ay, *app;
		QTextEdit *hpL, *nameL, *scoreL;
		QLabel *errorL, *nextWave, *endScore, *scoreList;
		QPushButton *startB, *restartB, *endB, *resumeB, *pauseB;
		QTextEdit* nameB;
		int gameSpeed, attack, ecount, level, pauseMe, score, anim, maxcount;
		bool paused, hasRed;
		QGraphicsPixmapItem *h1,*h2,*h3,*h4,*h5;
		
		QVBoxLayout *layout;
		QHBoxLayout *layout2, *layout3;
  	QWidget *holder, *holder2, *holder3;
		
		std::string pName;
		QString playerName;
		
		Thing* redShip;
		std::vector<Thing*> enemies;
		std::vector<Thing*> ebullets;
		std::vector<Thing*> pbullets;
		std::deque<Thing*> beampellets;
		std::multimap<int, std::string> highScores;
		
		Player* human;
		int maxhp;
		
		//queued actions
		int pvx, pvy;
		bool pattack;
};

#endif
