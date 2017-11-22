#include "gallerydialog.h"
#include "ui_gallerydialog.h"
#include "singleimgdialog.h"
#include "constants.h"
#include "converter.h"
#include "clickablelabel.h"
#include <stdio.h>
#include <QFile>
#include <QDebug>
#include <QIcon>



GalleryDialog::GalleryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GalleryDialog)
{
    ui->setupUi(this);
    index = 0;
    page = 0;
    btns[0] = ui->img1;
    btns[1] = ui->img2;
    btns[2] = ui->img3;
    btns[3] = ui->img4;
    Initialize(page * PAGE_WEIGHT + index);
}

void GalleryDialog::Initialize(int index){
    char file[256];
    for(int i=0; i < 4; i++){
        sprintf(file, CAM_N_PATH, index+i);
        qDebug() << "index : " << index+i << endl;
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
        QIcon icon(QPixmap::fromImage(img));
        btns[i]->setIcon(icon);
        btns[i]->setIconSize(QSize(427,247));
    }
}


void GalleryDialog::on_exitButton_clicked()
{
    close();
}

GalleryDialog::~GalleryDialog()
{
    delete ui;
}


void GalleryDialog::on_leftButton_clicked()
{
    page--;
    Initialize(page * PAGE_WEIGHT + index);
}

void GalleryDialog::on_rightButton_clicked()
{
    page++;
    Initialize(page * PAGE_WEIGHT + index);
}



void GalleryDialog::on_img1_clicked()
{
    APP_CONFIG::index = this->page * PAGE_WEIGHT + IMG_1;
    SingleImgDialog dig;
    dig.exec();
}

void GalleryDialog::on_img2_clicked()
{
    APP_CONFIG::index = this->page * PAGE_WEIGHT + IMG_2;
    SingleImgDialog dig;
    dig.exec();
}

void GalleryDialog::on_img3_clicked()
{
    APP_CONFIG::index = this->page * PAGE_WEIGHT + IMG_3;
    SingleImgDialog dig;
    dig.exec();
}

void GalleryDialog::on_img4_clicked()
{
    APP_CONFIG::index = this->page * PAGE_WEIGHT + IMG_4;
    SingleImgDialog dig;
    dig.exec();
}
