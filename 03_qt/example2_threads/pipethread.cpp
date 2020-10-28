#include "pipethread.h"

void PipeThread::sendLog(QString text){
    emit log("[PipeThread] " + text);
}

void PipeThread::run()
{
    char myfifo[] = "/tmp/myfifo";
    char text[80];


//    qDebug() << "Hola desde el hilo";

    mkfifo(myfifo, 0666);
//    qDebug() << "Abriendo tubería";
    sendLog("Abriendo tubería");
    fd = open(myfifo, O_RDONLY);
//    qDebug() << "Tubería Abierta";
    sendLog("Tubería Abierta");
    while(true){
//        qDebug() << "Esperando texto";
        sendLog("Esperando texto");
        read(fd, text, 80);
//        qDebug() << "Text recibido";
        sendLog("Text recibido");
//        qDebug() << QString(text);
        emit text_received( QString(text) );
    }
}

