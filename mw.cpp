#include "mw.h"

MainWindow::MainWindow() : QMainWindow(){
	// Master Timer
	timer = new QTimer;
	gameSpeed = 15;
	timer->setInterval(gameSpeed);
	srand(time(0));
	
	// Load Pictures
	bluepic = new QPixmap("images/blueship.png");
  
	//Initialize the Scenes and Views
  gameScene = new QGraphicsScene();
  gameView = new QGraphicsView(gameScene);
  
  //Set the attributes to the game scene
  //Image Credit: http://universe-beauty.com/Space-art/Unsorted-space-art/stars-and-planets-photo-img87-895p.html
  
  QBrush bg(QPixmap("images/background.png"));
  gameScene->setBackgroundBrush(bg);
  gameView->setFixedSize(500,700);
  
  //Connecting the timer
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  
  Thing* test1 = new Blue(bluepic, 100, 100);
  Thing* test2 = new Blue(bluepic, 200, 100);
  enemies.push_back(test1);
  enemies.push_back(test2);
  gameScene->addItem(test1);
  gameScene->addItem(test2);
}

void MainWindow::handleTimer(){
	for(unsigned int i = 0; i < enemies.size(); i++){
		enemies[i]->move();
	}
}

void MainWindow::show(){
	gameView->show();
	timer->start();
}
