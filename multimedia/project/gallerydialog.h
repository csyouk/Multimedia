#ifndef GALLERYDIALOG_H
#define GALLERYDIALOG_H

#include <QDialog>

namespace Ui {
class GalleryDialog;
}

class GalleryDialog : public QDialog
{
    Q_OBJECT
private:
    int img_cnt;
public:
    explicit GalleryDialog(QWidget *parent = 0);
    ~GalleryDialog();
    
private slots:
    void on_exitButton_clicked();

private:
    Ui::GalleryDialog *ui;
};

#endif // GALLERYDIALOG_H
