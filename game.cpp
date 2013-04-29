#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cmath>

#include <QtGui/QApplication>
#include "mw.h"

using namespace std;

/** @mainpage Starships (were meant to fly...)
@section description a game by Ruyan Chen for CSCI 102. for more details, please check the design doc. 
@section gameplay Arrow keys to move, space to shoot, esc to pause
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
        
    return a.exec();
}
