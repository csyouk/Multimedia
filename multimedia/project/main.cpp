#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("gulim");
    a.setFont(font);
    MainWindow w;
    w.show();


    return a.exec();
}
