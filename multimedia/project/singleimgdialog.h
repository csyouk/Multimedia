#ifndef SINGLEIMGDIALOG_H
#define SINGLEIMGDIALOG_H

#include <QDialog>

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

protected:
//    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QPoint pressPos;
    QPoint releasePos;
    char format[10];
    Ui::SingleImgDialog *ui;
    void changeImg(void);
};

#endif // SINGLEIMGDIALOG_H
