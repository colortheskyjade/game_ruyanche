#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cmath>

#include <QtGui/QApplication>
#include "mw.h"

using namespace std;

/** @mainpage Starships (were meant to fly...), a game by Ruyan Chen for CSCI 102
@section gameplay Gameplay



*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
        
    return a.exec();
}
