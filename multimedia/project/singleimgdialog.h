#ifndef SINGLEIMGDIALOG_H
#define SINGLEIMGDIALOG_H

#include <QDialog>
#include "constants.h"

namespace Ui {
class SingleImgDialog;
}

class SingleImgDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SingleImgDialog(QWidget *parent = 0);
    ~SingleImgDialog();
    
private slots:
    void on_exitButton_clicked();

    void on_rslider_sliderMoved(int position);

    void on_resetButton_clicked();

    void on_gslider_sliderMoved(int position);

    void on_bslider_sliderMoved(int position);

    void on_gslider_valueChanged(int value);

    void on_rslider_valueChanged(int value);

    void on_bslider_valueChanged(int value);

    void on_alphaSlider_sliderMoved(int position);

    void on_alphaSlider_valueChanged(int value);

    void on_screenshotButton_clicked();

protected:
//    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QPoint pressPos;
    QPoint releasePos;
    char format[10];
    Pixel p;
    Ui::SingleImgDialog *ui;
    void changeImg(Pixel &);
};

#endif // SINGLEIMGDIALOG_H
