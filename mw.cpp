#include "mw.h"

MainWindow::MainWindow() : QMainWindow(){
	// Initialize variables
	pvx = 0; pvy = 0;
	attack = 1;
	pattack = false;
	paused = false;
	maxhp = 10;
	
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
  
	pbullet = new QPixmap("images/bullet.png");
	bbullet = new QPixmap("images/bluebullet.png");
	gbullet = new QPixmap("images/greenbullet.png");
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
  
  //	Connecting the timer to many things
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  
  // Make the labels
  hpL = new QLabel("HP: 100%");
  hpL->setGeometry(QRect(355,570,100,25));
  hpL->setStyleSheet("background-color:rgba(0,0,0,0); color:#ffffff;");
  gameScene->addWidget(hpL);
  
  // I made the human player here
  human = new Player(apl,300,500,this);
  gameScene->addItem(human);
  
  //This is me testing
  Thing* test1 = new Red(ar1, ar2, ar3, 30, 25, this);
  enemies.push_back(test1);
  gameScene->addItem(test1);

  Thing* test2 = new Green(ag1, ag2, 50, 100, this);
  enemies.push_back(test2);
  gameScene->addItem(test2);
  
  Thing* test3 = new Blue(ab1, ab2, 50, 177, this);
  enemies.push_back(test3);
  gameScene->addItem(test3);
  
  Thing* test4 = new Purple(ap, 50, 400, this);
  enemies.push_back(test4);
  gameScene->addItem(test4);
  
	//Set the focus
	setFocus();
//	setCentralWidget(gameView);

}

//****************************
//****** SLOTS SLOTS *********
//****************************

void MainWindow::handleTimer(){
	

	// all enemies movement, actions, collisions
	std::deque<int> oenemies;
	for(unsigned int i = 0; i < enemies.size(); i++){
		// check the player bullets with the enemy
		for(unsigned int j = 0; j < pbullets.size(); j++){
			if(static_cast<Bullet*>(pbullets[j])->isCollides(enemies[i])){
				enemies[i]->gotHit(static_cast<Bullet*>(pbullets[j])->getAttack());
			}
		}
		if(enemies[i]->isValid()){
			enemies[i]->move();
			enemies[i]->action();
		}
		else{
			oenemies.push_front(i);
		}
	}
	
	for(int i = oenemies.size() - 1; i >= 0; i--){
		delete enemies[oenemies[i]];
		enemies.erase(enemies.begin() + oenemies[i]);
	}
	
	// move and check enemy bullets
	std::deque<int> obullets;
	for(unsigned int i = 0; i < ebullets.size(); i++){
		ebullets[i]->action();
		if(ebullets[i]->isValid()){
			ebullets[i]->move();
		}
		else{
			obullets.push_front(i);
		}
	}
		
	for(int i = obullets.size() - 1; i >= 0; i--){
		delete ebullets[obullets[i]];
		ebullets.erase(ebullets.begin() + obullets[i]);
	}
	
	// now move and check player bullets
	
	std::deque<int> oobullets;
	for(unsigned int i = 0; i < pbullets.size(); i++){
		pbullets[i]->action();
		if(pbullets[i]->isValid()){
			pbullets[i]->move();
		}
		else{
			oobullets.push_front(i);
		}
	}
		
	for(int i = oobullets.size() - 1; i >= 0; i--){
		delete pbullets[oobullets[i]];
		pbullets.erase(pbullets.begin() + oobullets[i]);
	}
	
	// check the enemy bullets with the player
	for(unsigned int i = 0; i < ebullets.size(); i++){
		if(static_cast<Bullet*>(ebullets[i])->isCollides(human)){
			human->gotHit(static_cast<Bullet*>(ebullets[i])->getAttack());
		}
	}
	
	// update player HP
	int temp = 100 * human->getHP() / maxhp;
	std::stringstream ss;
	ss << "HP: " << temp << "%";
	QString qstr = QString::fromStdString(ss.str());
	hpL->setText(qstr);
	
	
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

void MainWindow::makeGreenBullet(int x, int y){
	Thing* addMe = new Bullet(gbullet,x,y,false,attack);
	gameScene->addItem(addMe);
  ebullets.push_back(addMe);
	Thing* addMe2 = new Bullet(gbullet,x+2,y-10,false,attack);
	gameScene->addItem(addMe2);
  ebullets.push_back(addMe2);
}

void MainWindow::makeBlueBullet(int x, int y){
	Thing* addMe = new Bullet(bbullet,x,y,false,attack);
	gameScene->addItem(addMe);
  ebullets.push_back(addMe);
}

void MainWindow::makeBigBullet(int x, int y){
	Thing* addMe = new Bullet(widebulletpic,x,y,false,attack * 2);
	gameScene->addItem(addMe);
  ebullets.push_back(addMe);
}

void MainWindow::makePlayerBullet(int x, int y){
	Thing* addMe = new Bullet(pbullet,x,y,true,attack);
	gameScene->addItem(addMe);
  pbullets.push_back(addMe);
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
