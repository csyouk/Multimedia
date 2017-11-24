#include "singleimgdialog.h"
#include "ui_singleimgdialog.h"
#include "constants.h"
#include "converter.h"
#include <stdio.h>
#include <QFile>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>

SingleImgDialog::SingleImgDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingleImgDialog)
{
    ui->setupUi(this);
    setMouseTracking(true);
    char filePath[256];
    sprintf(filePath, CAM_N_PATH, APP_CONFIG::index);
    QString yuv422File(filePath);
    QFile file(yuv422File);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<OPEN_FILE_ERROR;
        return;
    }
    QByteArray array=file.readAll();

    convert_to_rgb32(array.data(), 1);

    QImage img((unsigned char *)rgb32,CAM_W,CAM_H,QImage::Format_RGB32);
    sprintf(format, "[ %d / %d ]", APP_CONFIG::index, APP_CONFIG::last);
    QString _format(format);
    ui->currentImgIndex->setText(_format);
    ui->currentImgIndex->setStyleSheet("font-size:20px");
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

void SingleImgDialog::on_rslider_sliderMoved(int position)
{
    qDebug() << "position : " << position;
}

//void SingleImgDialog::mouseMoveEvent(QMouseEvent * e){
//    qDebug() << e->pos().x() << "," << e->pos().y();
//    e->pos();
//}

void SingleImgDialog::mousePressEvent(QMouseEvent * e){
    pressPos = e->pos();
}

void SingleImgDialog::changeImg(void){
    char file[256];

    sprintf(file, CAM_N_PATH, APP_CONFIG::index);
    QString yuv422File(file);
    QFile File(yuv422File);
    if(!File.open(QIODevice::ReadOnly))
    {
         qDebug()<<"open file failed!";
         return;
    }
    QByteArray array=File.readAll();

    convert_to_rgb32(array.data(), 1);

    QImage img((unsigned char *)rgb32,CAM_W,CAM_H,QImage::Format_RGB32);
    sprintf(format, "[ %d / %d ]", APP_CONFIG::index, APP_CONFIG::last);
    QString _format(format);
    ui->currentImgIndex->setText(_format);
    ui->currentImgIndex->setStyleSheet("font-size:20px;font-weight:bold");
    ui->imgLabel->setPixmap(QPixmap::fromImage(img));
    ui->imgLabel->show();

}

void SingleImgDialog::mouseReleaseEvent(QMouseEvent * e){
//    qDebug() << "Release";
    releasePos = e->pos();
    int diff = releasePos.x() - pressPos.x();
    if(diff > SWIPE_THRESHOLD){
        // swipe right
        APP_CONFIG::index++;
        if(APP_CONFIG::index > APP_CONFIG::last){
            APP_CONFIG::index = APP_CONFIG::first;
        }
        changeImg();
    } else if(diff < -SWIPE_THRESHOLD){
        // swipe left
        APP_CONFIG::index--;
        if(APP_CONFIG::index > MAX_UINT - 100){
            APP_CONFIG::index = APP_CONFIG::last;
        }
        changeImg();
    }
    qDebug() << "Diff : " << diff << "/Index : " << APP_CONFIG::index;
}
