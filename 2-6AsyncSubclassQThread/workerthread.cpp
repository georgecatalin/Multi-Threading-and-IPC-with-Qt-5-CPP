#include "workerthread.h"

WorkerThread::WorkerThread(QObject *parent) : QThread(parent)
{
    qDebug()<<"WorkerThread constructor is running in thread: "<<QThread::currentThread();
}

WorkerThread::~WorkerThread()
{
    qDebug()<<"WorkerThread destructor is running in thread: "<<QThread::currentThread();
}

void WorkerThread::run()
{
   qDebug()<<"WorkerThread run method is running in thread: "<<QThread::currentThread();

    QTimer * myTimer=new QTimer();

    connect(myTimer,&QTimer::timeout,[=]()
    {
        qDebug()<<"Timeout running in thread: "<<QThread::currentThread();

    });

    myTimer->setInterval(1000);
    myTimer->start();

    // QTimer and QTCPSocket run continuously and they need an event loop
    exec();
}
