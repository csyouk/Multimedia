#include "gallerydialog.h"
#include "ui_gallerydialog.h"

GalleryDialog::GalleryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GalleryDialog)
{
    ui->setupUi(this);
    img_cnt = 0;
}

GalleryDialog::~GalleryDialog()
{
    delete ui;
}

void GalleryDialog::on_exitButton_clicked()
{
    char cmd[256];
    sprintf(cmd, "/mnt/nfs/cam/CAM%04d.bmp", img_cnt++);
    printf("%d\n", img_cnt);

    QPixmap pixmap(cmd);
}
