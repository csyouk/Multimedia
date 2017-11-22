#ifndef MUSICTHREAD_H
#define MUSICTHREAD_H

#include <QThread>

class MusicThread : public QThread
{
    Q_OBJECT
private:
    volatile bool stopped;
public:
    explicit MusicThread(QObject *parent = 0);
    void run();
    void stop();
    
signals:
    void sendCommand(int);
    
public slots:

};

#endif // MUSICTHREAD_H
