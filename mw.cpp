#include "mw.h"

MainWindow::MainWindow() : QMainWindow(){
	// Master Timer
	timer = new QTimer;
	gameSpeed = 15;
	timer->setInterval(gameSpeed);
	srand(time(0));
	
	// Load ALL THE PICTURES
	bluepic = new QPixmap("images/blueship.png");
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
  Thing* test1 = new Green(bluepic, 100, 100, this);
  Thing* test2 = new Green(bluepic, 300, 100, this);
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
