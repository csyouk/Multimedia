#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "musicdialog.h"
#include "cameradialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_musicButton_clicked()
{
    MusicDialog dig;
    dig.exec();
}

void MainWindow::on_cameraButton_clicked()
{
    CameraDialog dig;
    dig.exec();
}
