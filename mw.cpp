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
	heartpic = new QPixmap("images/heart.png");
	rainbow = new QPixmap("images/rainbow.png");
	
	h1 = new QGraphicsPixmapItem(*heartpic);
	h1->setPos(400, 575);
	h1->setVisible(false);
	h2 = new QGraphicsPixmapItem(*heartpic);
	h2->setPos(375, 575);
	h2->setVisible(false);
	h3 = new QGraphicsPixmapItem(*heartpic);
	h3->setPos(350, 575);
	h3->setVisible(false);
	h4 = new QGraphicsPixmapItem(*heartpic);
	h4->setPos(325, 575);
	h4->setVisible(false);
	h5 = new QGraphicsPixmapItem(*heartpic);
	h5->setPos(300, 575);
	h5->setVisible(false);
  
	//Initialize the Scenes and Views
  gameScene = new GScene(this);
  gameView = new QGraphicsView(gameScene);
  mainScene = new QGraphicsScene;
	mainView = new QGraphicsView(mainScene);
  
  mainView->setWindowTitle("Starships (were meant to fly...)");
  
	gameScene->addItem(h1);
	gameScene->addItem(h2);
	gameScene->addItem(h3);
	gameScene->addItem(h4);
	gameScene->addItem(h5);
  
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
  
  startB = new QPushButton("Start");
  startB->setGeometry(160, 250, 100, 60);
  startB->setStyleSheet("background-color:rgba(0,0,0,0); color:#ffffff; font-size:36px;");
  gameScene->addWidget(startB);
  
  nameB = new QTextEdit;
  nameB->setFixedHeight(28);
  nameB->setStyleSheet("background-color:rgb(0,0,0); color:#ffffff;");
   
  restartB = new QPushButton("Start");
  restartB->setFixedHeight(28);
  pauseB = new QPushButton("Pause");
  pauseB->setFixedHeight(28);
  endB = new QPushButton("Quit");
  endB->setFixedHeight(28);

  // Connecting the timer to many things
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  connect(timer2, SIGNAL(timeout()), this, SLOT(nextLevel()));
  connect(startB, SIGNAL(clicked()), this, SLOT(startGame()));
  connect(pauseB, SIGNAL(clicked()), this, SLOT(pauseGame()));
  connect(endB, SIGNAL(clicked()), this , SLOT(quitGame()));
  connect(restartB, SIGNAL(clicked()), this , SLOT(restartGame()));
  
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
  
  nextWave = new QLabel("Get ready for the next wave!");
  nextWave->setStyleSheet("background-color:rgba(0,0,0,1); color:#ffffff; font-size:24px;");
  nextWave->setGeometry(QRect(55,220,380,80));
  nextWave->hide();
  gameScene->addWidget(nextWave);
  
  endScore = new QLabel;
  endScore->setStyleSheet("background-color:rgba(0,0,0,1); color:#ffffff; font-size:26px;");
  endScore->setGeometry(QRect(0,150,425,80));
  endScore->setAlignment(Qt::AlignCenter);
  endScore->hide();
  gameScene->addWidget(endScore);
  
  // Set the layouts
  layout2->addWidget(restartB);
  layout2->addWidget(pauseB);
  layout2->addWidget(endB);
  layout->addWidget(holder2);
	layout->addWidget(gameView);
	layout->addWidget(nameB);
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
  mainView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
  gameView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

//****************************
//****** SLOTS SLOTS *********
//****************************

void MainWindow::handleTimer(){	

	// if player is dead
	if(human->isDead()){
		endGame();
		return;
	}
	
	// randomly add mothership
	if(!(rand() % 300) && !hasRed){
		redShip = new Red(ar1, ar2, ar3, 10, 15, this, human);
		enemies.push_back(redShip);
		gameScene->addItem(redShip);
		hasRed = true;
	}

	// add enemies

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
			if(enemies[i]->isPurple()){
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
	
	// now do the beam
	
	bool beamOK = true;
	
	for(unsigned int i = 0; i < beampellets.size(); i++){
		if(static_cast<Bullet*>(beampellets[i])->isCollides(human)){
			human->gotHit(100);
			beamOK = false;
		}
	}
	
	for(unsigned int i = 0; i < beampellets.size(); i++){
		beampellets[i]->action();
		beampellets[i]->move();
		if(!beampellets[i]->isValid()){
			static_cast<Red*>(redShip)->nextState();
			beamOK = false;
			break;
		}
	}
	
	if(!beamOK){
		for(unsigned int i = 0; i < beampellets.size(); i++){
			delete beampellets[i];
		}
		beampellets.clear();
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
	
	// heart display
	human->action();
	int getLives = human->getLives();
	if(getLives > 4){
		h5->setVisible(true);
	}
	else{
		h5->setVisible(false);
	}
	if(getLives > 3){
		h4->setVisible(true);
	}
	else{
		h4->setVisible(false);
	}
	if(getLives > 2){
		h3->setVisible(true);
	}
	else{
		h3->setVisible(false);
	}
	if(getLives > 1){
		h2->setVisible(true);
	}
	else{
		h2->setVisible(false);
	}
	if(getLives > 0){
		h1->setVisible(true);
	}
	else{
		h1->setVisible(false);
	}
	
	// handle lives
	if(human->getHP() <= 0){
		human->setHP(maxhp);
		human->setInvincible();
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
	Thing* addMe = new Bullet(widebulletpic,x,y,false,attack * 2, true);
	gameScene->addItem(addMe);
  ebullets.push_back(addMe);
}

void MainWindow::makePlayerBullet(int x, int y){
	Thing* addMe = new Bullet(pbullet,x,y,true,attack);
	gameScene->addItem(addMe);
  pbullets.push_back(addMe);
}

void MainWindow::fireBeam(int x, int y){
	Thing* addMe = new Bullet(rainbow,x,y,false,0, false, false, true);
	beampellets.push_back(addMe);
	gameScene->addItem(addMe);
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
	hasRed = false;
	errorL->hide();
	endScore->hide();
	if(nameB->toPlainText().isEmpty()){
		// display the warning label
		errorL->setText("You must enter a name in the\nbox below to start the game!");
		errorL->show();
		return;
	}
	
	pName = nameB->toPlainText().toUtf8().constData();
	playerName = "Pilot: " + nameB->toPlainText();
	nameL->setText(playerName);
	nameB->setVisible(false);
	holder3->setVisible(true);
	scoreL->setText("Score: 0");
	score = 0;

	level = 0;
  human = new Player(apl,300,500,this);
  gameScene->addItem(human);
  
  if(pName == "JBiebs"){
  	human->setGodly();
  }
  
  endLevel();
  startB->hide();
}

void MainWindow::nextLevel(){
	if(pauseMe == 20){
		timer2->stop();
		nextWave->hide();
		newLevel(++level);
		pauseMe = 0;
	}
	else{
		pauseMe++;
	}
}

void MainWindow::newLevel(int l){
	beampellets.clear();
	hasRed = false;
	ecount = 0;
	gameSpeed = gameSpeed * 3 / 5 + 1;
	attack += 1;
	maxhp += 5;
	if(l == 1){gameSpeed = 15; maxhp = 10; attack = 1;}
	timer->setInterval(gameSpeed);
	human->setHP(maxhp);
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
	nextWave->show();
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
	nameB->setVisible(true);
	holder3->setVisible(false);
	
	std::stringstream ss2;
	ss2 << "Score for " << pName << ": " << score;
	QString qstr2 =  QString::fromStdString(ss2.str());
	endScore->setText(qstr2);
	endScore->show();
	
	startB->show();
}

bool MainWindow::isPaused(){
	return paused;
}

void MainWindow::pauseGame(){
	if(paused){
		resumeGame();
		return;
	}
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
