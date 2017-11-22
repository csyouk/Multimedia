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
    int index;
    int page;
    int last_page;
    QPushButton * btns[4];
    void Initialize(int);
public:
    explicit GalleryDialog(QWidget *parent = 0);
    ~GalleryDialog();
    
private slots:
    void on_exitButton_clicked();

    void on_rightButton_clicked();

    void on_leftButton_clicked();

    void on_img1_clicked();

    void on_img2_clicked();

    void on_img3_clicked();

    void on_img4_clicked();

private:
    Ui::GalleryDialog *ui;
};

#endif // GALLERYDIALOG_H
