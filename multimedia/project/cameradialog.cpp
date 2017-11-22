#include "cameradialog.h"
#include "ui_cameradialog.h"
#include <stdio.h>

#define NTHUMBNAILS 8

CameraDialog::CameraDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraDialog)
{
    capture_count = 0;
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    run_v4l2();
}



CameraDialog::~CameraDialog()
{
    delete ui;
}

void CameraDialog::on_exitButton_clicked()
{
    write(fd_pipe_stdin[1], "e\n", 2);
    sleep(1);
    close();
}

void CameraDialog::run_v4l2(void){
    pid_t pid_temp;

    if(pipe(fd_pipe_stdin) == -1) exit(-1);
    if(pipe(fd_pipe_stdout) == -1) exit(-1);

    pid_temp = fork();
    if(pid_temp == -1) exit(-1);
    else if(pid_temp == 0){
        ::close(0);
        dup(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdin[1]);
        ::close(1);
        dup(fd_pipe_stdout[1]);
        ::close(fd_pipe_stdout[1]);
        ::close(fd_pipe_stdout[0]);
        execlp("./v4l2test", "v4l2test","-d","/dev/video5","-c","700000", "-b","/dev/fb0","-x","0","-y","0","-a","1",NULL);
    }else{
        ::close(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdout[1]);
    }
}

void CameraDialog::on_captureButton_clicked()
{
    char fname[128];
    char str[128];
    char cmd[256];
    int xpos[NTHUMBNAILS] = {650,840,650,840,650,840,650,840,};
    int ypos[NTHUMBNAILS] = {0,0,120,120,240,240,360,360};

    printf("Captue %d\n", capture_count);
    sprintf(fname, "./cam/CAM%04d", capture_count);

    sprintf(str, "c ./cam/CAM%04d\n", capture_count);
    printf("send : %s\n", str);
    fflush(stdout);

    write(fd_pipe_stdin[1], str, strlen(str));

    read(fd_pipe_stdout[0], str, 64);

    printf("recv : %s\n", str);
    fflush(stdout);

    sprintf(cmd, "./v4l2test -d /dev/video5 -c 70000 -b /dev/fb0 -x %d -y %d -a 3 -n %s", xpos[capture_count%NTHUMBNAILS], ypos[capture_count%NTHUMBNAILS], fname);
    system(cmd);

    write(fd_pipe_stdin[1],"e\n",2);
    sleep(1);

    sprintf(cmd,"./conv_bmp -s 640x480 -o ./cam/CAM%04d -d /dev/video5 -f jpeg",capture_count++);
    system(cmd);
    CameraDialog::run_v4l2();
}

void CameraDialog::on_galleryButton_clicked()
{


}










