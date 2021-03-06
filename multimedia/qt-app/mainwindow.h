#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtextcodec.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_musicButton_clicked();

    void on_cameraButton_clicked();

private:
    Ui::MainWindow *ui;
    QTextCodec *codec;
};

#endif // MAINWINDOW_H
