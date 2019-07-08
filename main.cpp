#include "mainwindow.h"
#include "file.h"

#include <QApplication>
#include <QDebug>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}


//C:\Users\Vova\Documents\Qt\window\123.txt
