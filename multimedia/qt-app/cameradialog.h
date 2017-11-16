#ifndef CAMERADIALOG_H
#define CAMERADIALOG_H

#include <QDialog>

namespace Ui {
class CameraDialog;
}

class CameraDialog : public QDialog
{
    Q_OBJECT
private:
    int fd_pipe_stdin[2];
    int fd_pipe_stdout[2];
    int capture_count;
public:
    explicit CameraDialog(QWidget *parent = 0);
    ~CameraDialog();
    
private slots:
    void on_exitButton_clicked();

    void on_captureButton_clicked();

private:
    Ui::CameraDialog *ui;
};

#endif // CAMERADIALOG_H
