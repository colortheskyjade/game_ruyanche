#include "mw.h"

MainWindow::MainWindow() : QMainWindow(){
	// Initialize variables
	pvx = 0; pvy = 0;
	attack = 1;
	pattack = false;
	paused = false;
	maxhp = 10;
	level = 1;
	pauseMe = 0;
	human = NULL;
	
	// Master Timer
	timer = new QTimer;
	gameSpeed = 14;
	timer->setInterval(gameSpeed);
	srand(time(0));
	
	// Secondary Timer
	timer2 = new QTimer;
	timer2->setInterval(100);
	
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
  mainScene = new QGraphicsScene;
	mainView = new QGraphicsView(mainScene);
  
  holder = new QWidget;
  holder2 = new QWidget;
  holder3 = new QWidget;
	layout = new QVBoxLayout(holder);
	layout2 = new QHBoxLayout(holder2);
	layout3 = new QHBoxLayout(holder3);
  
  //Set the attributes to the game scene
  //Image Credit: http://universe-beauty.com/Space-art/Unsorted-space-art/stars-and-planets-photo-img87-895p.html
  
  QBrush bg(QPixmap("images/background.png"));
  gameScene->setBackgroundBrush(bg);
  gameScene->setSceneRect(0,0,425,600);
  gameView->setFixedSize(430,605);
 	gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  
  // Making buttons
  // Playas love buttons
  // Ohhhh yeahhhhhh
  
  startB = new QPushButton("Start");
  startB->setGeometry(160, 250, 100, 60);
  startB->setStyleSheet("background-color:rgba(0,0,0,0); color:#ffffff; font-size:36px;");
  gameScene->addWidget(startB);
  
  nameB = new QTextEdit;
  nameB->setFixedHeight(28);
  nameB->setStyleSheet("background-color:rgb(0,0,0); color:#ffffff;");
  
  pauseB = new QPushButton("Pause");
  pauseB->setFixedHeight(28);
//  pauseB->setStyleSheet("background-color:rgba(0,0,0,1); color:#ffffff;");
  
  // Connecting the timer to many things
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  connect(timer2, SIGNAL(timeout()), this, SLOT(nextLevel()));
  connect(startB, SIGNAL(clicked()), this, SLOT(startGame()));
  
  // Make the labels  
  nameL = new QTextEdit;
  nameL->setStyleSheet("background-color:rgb(0,0,0); color:#ffffff;");
  nameL->setFixedHeight(28);
  nameL->setFixedWidth(200);
  nameL->setReadOnly(true);
  layout3->addWidget(nameL);
    
  scoreL = new QTextEdit;
  scoreL->setStyleSheet("background-color:rgb(0,0,0); color:#ffffff;");
  scoreL->setFixedHeight(28);
  scoreL->setFixedWidth(130);
  scoreL->setReadOnly(true);
  layout3->addWidget(scoreL);
  
  hpL = new QTextEdit;
  hpL->setStyleSheet("background-color:rgb(0,0,0); color:#ffffff;");
  hpL->setFixedHeight(28);
  hpL->setFixedWidth(80);
  hpL->setReadOnly(true);
  layout3->addWidget(hpL);
  
  errorL = new QLabel;
  errorL->setStyleSheet("background-color:rgba(0,0,0,1); color:#ffffff; font-size:24px;");
  errorL->setGeometry(QRect(60,520,380,80));
  gameScene->addWidget(errorL);
  
  
  // Set the layouts
  layout2->addWidget(nameB);
  layout2->addWidget(pauseB);
	layout->addWidget(gameView);
	layout->addWidget(holder2);
	holder3->setVisible(false);
	layout->addWidget(holder3);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setMargin(0);
	layout2->setContentsMargins(0, 0, 0, 0);
	layout2->setMargin(0);
	layout3->setContentsMargins(0, 0, 0, 0);
	layout3->setMargin(0);
	
  mainScene->addWidget(holder);
  mainView->setFixedSize(460,710);
 	mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  
  gameView->setAttribute(Qt::WA_OpaquePaintEvent);
  gameView->setAttribute(Qt::WA_NoSystemBackground);
 	mainView->setAttribute(Qt::WA_OpaquePaintEvent);
  mainView->setAttribute(Qt::WA_NoSystemBackground);
//  mainView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
//  gameView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

//****************************
//****** SLOTS SLOTS *********
//****************************

void MainWindow::handleTimer(){
	if(enemies.empty() && ecount == 17){
		endLevel();
	}
	
	if(ecount < 17){
		int select = rand() % 7;
		Thing * addMe;
		
		if(select < 4){
			addMe =  new Blue(ab1, ab2, rand() % 280 + 10, rand() % 250 + 50, this);
		}
		else if(select < 6){
			addMe =  new Green(ag1, ag2, rand() % 280 + 10, rand() % 250 + 50, this);
		}
		else{
			addMe =  new Purple(ap, rand() % 280 + 10, 350, this, human);
		}
		
		enemies.push_back(addMe);
		gameScene->addItem(addMe);
		
		ecount++;
	}

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
			if(enemies[i]->purple){
				static_cast<Purple*>(enemies[i])->isCollides();
			}
		}
		else{
			oenemies.push_front(i);
		}
	}
	
	while(!oenemies.empty()){
		score += enemies[oenemies[0]]->getScore();
		delete enemies[oenemies[0]];
		enemies.erase(enemies.begin() + oenemies[0]);
		oenemies.pop_front();
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
		
	while(!obullets.empty()){
		delete ebullets[obullets[0]];
		ebullets.erase(ebullets.begin() + obullets[0]);
		obullets.pop_front();
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
		
	while(!oobullets.empty()){
		delete pbullets[oobullets[0]];
		pbullets.erase(pbullets.begin() + oobullets[0]);
		oobullets.pop_front();
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
	
	human->action();
	
	// do the queued player things
	if(pvx || pvy){
		human->move(pvx,pvy);
		pvx = 0; pvy = 0;
	}
	if(pattack){
		human->doAttack();
		pattack = false;
	}
	
	// update score
	std::stringstream ss2;
	ss2 << "Score: " << score;
	QString qstr2 = QString::fromStdString(ss2.str());
	scoreL->setText(qstr2);
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

void MainWindow::startGame(){
	errorL->hide();
	if(nameB->toPlainText().isEmpty()){
		// display the warning label
		errorL->setText("You must enter a name in the\nbox below to start the game!");
		errorL->show();
		return;
	}
	
	playerName = "Pilot: " + nameB->toPlainText();
	nameL->setText(playerName);
	holder2->setVisible(false);
	holder3->setVisible(true);
	scoreL->setText("Score: 0");
	score = 0;

	level = 0;
  human = new Player(apl,300,500,this);
  gameScene->addItem(human);
  
  endLevel();
  startB->hide();
}

void MainWindow::nextLevel(){
	if(pauseMe == 50){
		timer2->stop();
		newLevel(++level);
		pauseMe = 0;
	}
	else{
		pauseMe++;
	}
}

void MainWindow::newLevel(int l){
	ecount = 0;
	gameSpeed = gameSpeed * 3 / 5 + 1;
	maxhp += 5;
	if(l == 1){gameSpeed = 15; maxhp = 10;}
	timer->setInterval(gameSpeed);
	human->setInvincible();
	timer->start();
}

void MainWindow::endLevel(){
	while(!ebullets.empty()){
		delete ebullets[0];
		ebullets.erase(ebullets.begin());
	}
	while(!pbullets.empty()){
		delete pbullets[0];
		pbullets.erase(pbullets.begin());
	}
	while(!enemies.empty()){
		delete enemies[0];
		enemies.erase(enemies.begin());
	}
	timer->stop();
	timer2->start();
}

void MainWindow::endGame(){
	while(!ebullets.empty()){
		delete ebullets[0];
		ebullets.erase(ebullets.begin());
	}
	while(!pbullets.empty()){
		delete pbullets[0];
		pbullets.erase(pbullets.begin());
	}
	while(!enemies.empty()){
		delete enemies[0];
		enemies.erase(enemies.begin());
	}
	timer->stop();
	delete human;
	human = NULL;
}

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
	mainView->show();
}
