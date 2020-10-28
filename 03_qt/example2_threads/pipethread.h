#ifndef PIPETHREAD_H
#define PIPETHREAD_H

#include <QThread>
#include <QDebug>

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

class PipeThread : public QThread
{
    Q_OBJECT

protected:
    void run();

signals:
    void text_received(QString text);
    void log(QString text);

private:
    void sendLog(QString text);
    int fd;

};

#endif // PIPETHREAD_H
