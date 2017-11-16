#include "musicthread.h"

MusicThread::MusicThread(QObject *parent) :
    QThread(parent)
{
    stopped = false;
}

void MusicThread::run()
{
    int cnt = 0;
    while(stopped == false){
        msleep(100);
        if(cnt++ == 10){
            cnt = 0;
            emit sendCommand(1);
        }
    }
}

void MusicThread::stop()
{
    stopped = true;
}
