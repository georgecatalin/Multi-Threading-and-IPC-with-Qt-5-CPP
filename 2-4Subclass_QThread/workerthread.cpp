#include "workerthread.h"

Workerthread::Workerthread(QObject *parent) : QThread(parent)
{
    qDebug()<<"Workerthread constructor in running in this thread: "<<QThread::currentThread();
}

Workerthread::~Workerthread()
{
    qDebug()<<"Workerthread destructor is running in the thread: "<<QThread::currentThread();
}

void Workerthread::run()
{
    qDebug()<<"run method of Workerthread is running in the thread: "<<QThread::currentThread();

    for (int i{0};i<1000000 ;i++)
    {
        if (i%10000==0)
        {
            double percentage=(i/1000000.0)*100.0;
            emit currentCount(QVariant::fromValue(percentage).toInt());
        }
    }

    //Set it to an event loop which keeps on waiting stuff from the run() function
    //exec();
}
