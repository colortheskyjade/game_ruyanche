#include "mw.h"

MainWindow::MainWindow() : QMainWindow(){
	// Master Timer
	timer = new QTimer;
	gameSpeed = 15;
	timer->setInterval(gameSpeed);
	srand(time(0));
	
	// Load ALL THE PICTURES
	
	ab1 = new QPixmap("images/actualblue-1.png");
  ab2 = new QPixmap("images/actualblue-2.png");
  ag1 = new QPixmap("images/actualgreen-1.png");
  ag2 = new QPixmap("images/actualgreen-2.png");
  apl = new QPixmap("images/actualplayer.png");
  ap = new QPixmap("images/actualpurple.png");
  ar1 = new QPixmap("images/actualred-1.png");
  ar2 = new QPixmap("images/actualred-2.png");
  ar3 = new QPixmap("images/actualred-3.png");
  
	bulletpic = new QPixmap("images/bullet.png");
  
	//Initialize the Scenes and Views
  gameScene = new QGraphicsScene();
  gameView = new QGraphicsView(gameScene);
  
  //Set the attributes to the game scene
  //Image Credit: http://universe-beauty.com/Space-art/Unsorted-space-art/stars-and-planets-photo-img87-895p.html
  
  QBrush bg(QPixmap("images/background.png"));
  gameScene->setBackgroundBrush(bg);
  gameScene->setSceneRect(0,0,425,600);
  gameView->setFixedSize(430,605);
  
  //Connecting the timer to many things
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  
  //This is me testing
  Thing* test1 = new Green(ag1, 100, 100, this);
  Thing* test2 = new Green(ag2, 300, 300, this);
  enemies.push_back(test1);
  enemies.push_back(test2);
  gameScene->addItem(test1);
  gameScene->addItem(test2);
}

void MainWindow::handleTimer(){
	for(unsigned int i = 0; i < enemies.size(); i++){
		enemies[i]->move();
		enemies[i]->action();
	}
	for(unsigned int i = 0; i < bullets.size(); i++){
		bullets[i]->move();
		bullets[i]->action();
	}
}

void MainWindow::makeBullet(int x, int y, bool up, int attack){
	Thing* addMe = new Bullet(bulletpic,x,y,up,attack);
	gameScene->addItem(addMe);
  bullets.push_back(addMe);
}

void MainWindow::show(){
	gameView->show();
	timer->start();
}
