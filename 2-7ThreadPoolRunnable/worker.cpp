#include "worker.h"

Worker::Worker()
{
    qDebug()<<"The Worker Constructor is running in the thread: "<<QThread::currentThread();
}

Worker::~Worker()
{
    qDebug()<<"The Worker Destructor is running in the thread: "<<QThread::currentThread();
}

void Worker::run()
{
    qDebug()<<"The Worker Run method is running in the thread: "<<QThread::currentThread();

    for (int i{0};i<1000000 ;i++ )
    {
        if (i%10000==0)
        {
           double percentage=(i/1000000.0)*100.0;
           qDebug()<<"Current percentage is: "<<percentage;
        }
    }
}
