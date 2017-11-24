#include "mainwindow.h"
#include "cameradialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QFont font("gulim");
//    a.setFont(font);
    MainWindow w;
    w.show();

//    CameraDialog dig;
//    dig.exec();

    return a.exec();
}
