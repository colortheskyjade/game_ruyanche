#include "mw.h"

MainWindow::MainWindow() : QMainWindow(){
	// Initialize variables
	pvx = 0; pvy = 0;
	attack = 1;
	pattack = false;
	paused = false;
	
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
	widebulletpic = new QPixmap("images/redbullet.png");
  
	//Initialize the Scenes and Views
  gameScene = new GScene(this);
  gameView = new QGraphicsView(gameScene);
  
  //Set the attributes to the game scene
  //Image Credit: http://universe-beauty.com/Space-art/Unsorted-space-art/stars-and-planets-photo-img87-895p.html
  
  QBrush bg(QPixmap("images/background.png"));
  gameScene->setBackgroundBrush(bg);
  gameScene->setSceneRect(0,0,425,600);
  gameView->setFixedSize(430,605);
  
  //Connecting the timer to many things
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  
  human = new Player(apl,300,500,this);
  gameScene->addItem(human);
  
  //This is me testing
  Thing* test1 = new Red(ar1, ar2, ar3, 50, 100, this);
//  Thing* test2 = new Purple(ap, 300, 300, this);
  enemies.push_back(test1);
//  enemies.push_back(test2);
  gameScene->addItem(test1);
//  gameScene->addItem(test2);

	//Set the focus
	setFocus();
//	setCentralWidget(gameView);

}

//****************************
//****** SLOTS SLOTS *********
//****************************

void MainWindow::handleTimer(){
	// move all enemies
	for(unsigned int i = 0; i < enemies.size(); i++){
		enemies[i]->move();
		enemies[i]->action();
	}
	// move all bullets
	for(unsigned int i = 0; i < bullets.size(); i++){
		bullets[i]->move();
		bullets[i]->action();
	}
	// do the queued player things
	if(pvx || pvy){
		human->move(pvx,pvy);
		pvx = 0; pvy = 0;
	}
	if(pattack){
		human->doAttack();
		pattack = false;
	}
}

//****************************
//**** BULLETS BULLETS *******
//****************************

void MainWindow::makeBullet(int x, int y, bool up, int attack2){
	Thing* addMe = new Bullet(bulletpic,x,y,up,attack);
	gameScene->addItem(addMe);
  bullets.push_back(addMe);
}

void MainWindow::makeBigBullet(int x, int y, int attack2){
	Thing* addMe = new Bullet(widebulletpic,x,y,false,attack);
	gameScene->addItem(addMe);
  bullets.push_back(addMe);
}

void MainWindow::makePlayerBullet(int x, int y){
	Thing* addMe = new Bullet(bulletpic,x,y,true,attack);
	gameScene->addItem(addMe);
  bullets.push_back(addMe);
}

//****************************
//*** PLAYER DOES STUFF ******
//****************************

void MainWindow::moveP(int vx, int vy){
	pvx = vx;
	pvy = vy;
}

void MainWindow::shootP(){
	pattack = true;
}

//****************************
//*** GAME STATE CHANGE ******
//****************************

bool MainWindow::isPaused(){
	return paused;
}

void MainWindow::pauseGame(){
	timer->stop();
	paused = true;
}

void MainWindow::resumeGame(){
	timer->start();
	paused = false;
}

void MainWindow::show(){
	gameView->show();
	timer->start();
}
