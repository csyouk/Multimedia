#include "singleimgdialog.h"
#include "ui_singleimgdialog.h"
#include "constants.h"
#include "converter.h"
#include <stdio.h>
#include <QFile>
#include <QDebug>


SingleImgDialog::SingleImgDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingleImgDialog)
{
    ui->setupUi(this);


    char filePath[256];
    sprintf(filePath, CAM_N_PATH, APP_CONFIG::index);
    QString yuv422File(filePath);
    QFile file(yuv422File);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<OPEN_FILE_ERROR;
        return;
    }
    QString camPath(CAM_PATH);

    QByteArray array=file.readAll();

    convert_to_rgb32(array.data(), 1);

    QImage img((unsigned char *)rgb32,CAM_W,CAM_H,QImage::Format_RGB32);

    ui->imgLabel->setPixmap(QPixmap::fromImage(img));
    ui->imgLabel->show();

}

SingleImgDialog::~SingleImgDialog()
{
    delete ui;
}

void SingleImgDialog::on_exitButton_clicked()
{
    close();
}
