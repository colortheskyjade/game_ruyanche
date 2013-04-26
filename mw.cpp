#include "mw.h"

MainWindow::MainWindow() : QMainWindow(){
	// Master Timer
	timer = new QTimer;
	gameSpeed = 15;
	timer->setInterval(gameSpeed);
	srand(time(0));
	
	// Load ALL THE PICTURES
	bluepic = new QPixmap("images/blueship.png");
  
	//Initialize the Scenes and Views
  gameScene = new QGraphicsScene();
  gameView = new QGraphicsView(gameScene);
  
  //Set the attributes to the game scene
  //Image Credit: http://universe-beauty.com/Space-art/Unsorted-space-art/stars-and-planets-photo-img87-895p.html
  
  QBrush bg(QPixmap("images/background.png"));
  gameScene->setBackgroundBrush(bg);
  gameScene->setSceneRect(0,0,500,700);
  gameView->setFixedSize(505,705);
  
  //Connecting the timer to many things
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  
  
  //This is me testing
  Thing* test1 = new Blue(bluepic, 100, 100, this);
  Thing* test2 = new Blue(bluepic, 375, 100, this);
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
}

void MainWindow::makeBullet(int x, int y, bool up, bool red, int attack){
  bullets.push_back(new Bullet(bulletpic,x,y,up,red,attack));
}

void MainWindow::show(){
	gameView->show();
	timer->start();
}
