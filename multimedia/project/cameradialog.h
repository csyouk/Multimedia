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
    void update_capture_count(void);

public:
    explicit CameraDialog(QWidget *parent = 0);
    void run_v4l2(void);
    ~CameraDialog();
    
private slots:
    void on_exitButton_clicked();

    void on_captureButton_clicked();

    void on_galleryButton_clicked();

    void on_runButton_clicked();

private:
    Ui::CameraDialog *ui;
};

#endif // CAMERADIALOG_H
