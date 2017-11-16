#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H

#include <QDialog>
#include <musicthread.h>

namespace Ui {
class MusicDialog;
}

class MusicDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MusicDialog(QWidget *parent = 0);
    ~MusicDialog();
    
private slots:
    void on_exitButton_clicked();

    void on_openButton_clicked();

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_stopButton_clicked();

public slots:
    void handleCommand(int);

private:
    Ui::MusicDialog *ui;
    int fd_pipe[2];
    MusicThread *musicThread;
};

#endif // MUSICDIALOG_H
