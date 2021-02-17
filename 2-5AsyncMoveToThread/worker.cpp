#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

Worker::~Worker()
{
    qDebug()<<"Worker destructor is running in thread: "<<QThread::currentThread();
}

void Worker::doWork()
{
    QTimer * myTimer=new QTimer();

    connect(myTimer,&QTimer::timeout,[=]()
    {
        qDebug()<<"Time out. Running in thread: "<<QThread::currentThread();
    });

    myTimer->setInterval(1000);
    myTimer->start();
}
