#include "mythread.h"
//#include <QDebug>

MyThread::MyThread(QObject *parent) : QThread(parent)
{
    stopped = false;
}
void MyThread::run(){
    qreal i = 0;
    while(!stopped){
//        qDebug() << QString("in MyThread: %1").arg(i);
        emit Running(i);   //通过发射信号控制
        msleep(200);
        i++;
    }
    stopped = false;
}
void MyThread::stop(){
    stopped = true;
}
