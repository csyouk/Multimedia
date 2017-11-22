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

private:
    Ui::SingleImgDialog *ui;
};

#endif // SINGLEIMGDIALOG_H
