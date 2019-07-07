#include "mainwindow.h"
#include "file.h"

#include <QApplication>
#include <QDebug>
#include <fstream>
#include <iostream>

using namespace std;

/*liststr massive(const string path){
    string s =read_lines(path);
    QString qs = QString::fromStdString(s);
    QStringList qsl = qs.split(' ', QString::SkipEmptyParts);
    qsl.sort();

    liststr a;
    for(int i = 1; i < qsl.size();i++)
    {
        int k = 1;
        string s1 = qsl[i-1].toStdString();
        while(i<qsl.size() && qsl[i-1] == qsl[i]){
            k++;
            i++;
        }

        a.push_back(s1,to_string(k));
    }
    return a;
}
*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}


//C:\Users\Vova\Documents\Qt\window\123.txt
