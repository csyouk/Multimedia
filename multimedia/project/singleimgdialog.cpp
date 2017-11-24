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
    p.data = 0;
    changeImg(p);
}

SingleImgDialog::~SingleImgDialog()
{
    delete ui;
}

void SingleImgDialog::on_exitButton_clicked()
{
    close();
}

void SingleImgDialog::mousePressEvent(QMouseEvent * e){
    pressPos = e->pos();
}

void SingleImgDialog::changeImg(Pixel & p){
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

    yuv422_to_rgb32_with_adder(array.data(), p, 1);

    QImage img((unsigned char *)RGB32,CAM_W,CAM_H,QImage::Format_RGB32);
    sprintf(format, "[ %d / %d ]", APP_CONFIG::index, APP_CONFIG::last);
    QString _format(format);
    ui->currentImgIndex->setText(_format);
    ui->currentImgIndex->setStyleSheet("font-size:20px;font-weight:bold");
    ui->imgLabel->setPixmap(QPixmap::fromImage(img));

    ui->imgLabel->show();

}

void SingleImgDialog::mouseReleaseEvent(QMouseEvent * e){
    releasePos = e->pos();
    int diff = releasePos.x() - pressPos.x();
    if(diff > SWIPE_THRESHOLD){
        // swipe right
        APP_CONFIG::index++;
        if(APP_CONFIG::index > APP_CONFIG::last){
            APP_CONFIG::index = APP_CONFIG::first;
        }
        changeImg(p);
    } else if(diff < -SWIPE_THRESHOLD){
        // swipe left
        APP_CONFIG::index--;
        if(APP_CONFIG::index > MAX_UINT - 100){
            APP_CONFIG::index = APP_CONFIG::last;
        }
        changeImg(p);
    }
    qDebug() << "Diff : " << diff << "/Index : " << APP_CONFIG::index;
}

void SingleImgDialog::on_resetButton_clicked()
{
    ui->rslider->setValue(50);
    ui->rslider->setSliderPosition(50);
    ui->gslider->setValue(50);
    ui->gslider->setSliderPosition(50);
    ui->bslider->setValue(50);
    ui->bslider->setSliderPosition(50);
    ui->alphaSlider->setValue(99);
    ui->alphaSlider->setSliderPosition(99);
    p.data = 0;
    changeImg(p);
}

void SingleImgDialog::on_rslider_sliderMoved(int position)
{
//    qDebug() << "position : " << position;
    Macro_Write_Block(p.data, 0xff, position - COLOR_BASE, 16);
    changeImg(p);
}

void SingleImgDialog::on_gslider_sliderMoved(int position)
{
    Macro_Write_Block(p.data, 0xff, position - COLOR_BASE, 8);
    changeImg(p);

}

void SingleImgDialog::on_bslider_sliderMoved(int position)
{
    Macro_Write_Block(p.data, 0xff, position - COLOR_BASE, 0);
    changeImg(p);

}

void SingleImgDialog::on_rslider_valueChanged(int value)
{
    Macro_Write_Block(p.data, 0xff, value - COLOR_BASE, 16);
    changeImg(p);
}
void SingleImgDialog::on_gslider_valueChanged(int value)
{
    Macro_Write_Block(p.data, 0xff, value - COLOR_BASE, 8);
    changeImg(p);
}

void SingleImgDialog::on_bslider_valueChanged(int value)
{
    Macro_Write_Block(p.data, 0xff, value - COLOR_BASE, 0);
    changeImg(p);
}


void SingleImgDialog::on_alphaSlider_sliderMoved(int position)
{
    Macro_Write_Block(p.data, 0xff, position - COLOR_BASE, 24);
    changeImg(p);
}

void SingleImgDialog::on_alphaSlider_valueChanged(int value)
{
    Macro_Write_Block(p.data, 0xff, value - COLOR_BASE, 24);
    changeImg(p);
}

void SingleImgDialog::on_screenshotButton_clicked()
{
    char file[256];
    rgb32_to_yuv422(RGB32);
    sprintf(file, "./cam/CAM%04d",  APP_CONFIG::last+1);
    if(capture_to_file((void *)RGB32, sizeof(RGB32), file) == -1){
        qDebug() << "File Save Failed!";
        return;
    }
    qDebug() << "File Successfully Saved!";
    APP_CONFIG::last++;
    sprintf(format, "[ %d / %d ]", APP_CONFIG::index, APP_CONFIG::last);
    QString _format(format);
    ui->currentImgIndex->setText(_format);
    ui->currentImgIndex->setStyleSheet("font-size:20px;font-weight:bold");
}
