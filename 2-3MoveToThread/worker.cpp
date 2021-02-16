#include "worker.h"


Worker::Worker(QObject *parent) : QObject(parent)
{
    qDebug()<<"Worker constructor is in this thread: "<<QThread::currentThread();
}

Worker::~Worker()
{
    qDebug()<<"Worker is destroyed and the destructor is running in this thread: "<< QThread::currentThread();
}

void Worker::doCounting()
{
    // this code is going to run in a secondary/background thread

    qDebug()<<"Worker counting is happening in this thread: "<<QThread::currentThread();

    for (int i{0};i<1000000  ;i++ )
    {
        double percentage=(i/1000000.0)*100.0;


        //qDebug()<<"Percentage :"<<percentage;

        if (i%10000==0)
        {
           emit currentCount(QVariant::fromValue(percentage).toInt());
        }

    }

    emit countFinished();
}


