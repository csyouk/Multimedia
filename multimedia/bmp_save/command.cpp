#include "cameradialog.h"
#include "ui_cameradialog.h"
#include <stdio.h>
#include <QFileDialog>

CameraDialog::CameraDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraDialog)
{
    ui->setupUi(this);
    pid_t pid_temp;
    zoom_ratio=1;
    capture_count=0;
    if(pipe(fd_pipe_stdin)==-1) exit(-1);
    if(pipe(fd_pipe_stdout)==-1) exit(-1);
    pid_temp=fork();
    if(pid_temp==-1) exit(-1);
    else if(pid_temp==0)
    {
        ::close(0);
        dup(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdin[1]);
        ::close(1);
        dup(fd_pipe_stdout[1]);
        ::close(fd_pipe_stdout[1]);
        ::close(fd_pipe_stdout[0]);

           execlp("./v4l2test","v4l2test","-d","/dev/video5","-c","700000","-b","/dev/fb0",
                  "-x","10","-y","40","-a","2",NULL);
    }
    else
    {
        ::close(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdout[1]);
    }
}

CameraDialog::~CameraDialog()
{
    delete ui;
}


void CameraDialog::on_exitButton_clicked()
{
    write(fd_pipe_stdin[1],"e\n",2);
    sleep(1);
    close();
}

void CameraDialog::on_captureButton_clicked()
{
    char str[128];
    char cmd[256];

    sprintf(str,"c ./cam/CAM%04d\n",capture_count);
    printf("send: %s",str);
    fflush(stdout);


    write(fd_pipe_stdin[1],str,strlen(str));
    read(fd_pipe_stdout[0],str,64);
    str[2]='\0';
    printf("recv : %s\n",str);
    fflush(stdout);

   //sprintf(cmd,"./v4l2test v4l2test -d /dev/video5 -c 700000 -b /dev/fb0 -x 400 -y 100 -a %d -n %s", zoom_ratio, fname);

   write(fd_pipe_stdin[1],"e\n",2);
   sleep(1);

   sprintf(cmd,"./v4l2 -s 640x480 -o test%d -d /dev/video5 -f jpeg",capture_count++);
   system(cmd);
   write(fd_pipe_stdin[1],"c\n",2);
}














-
