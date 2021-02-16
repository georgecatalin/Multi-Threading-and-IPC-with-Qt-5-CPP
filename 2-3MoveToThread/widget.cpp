#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<"Widget constructor is running in the GUI thread: "<<thread();
    qDebug()<<"The current thread in the Widget constructor is :"<<QThread::currentThread();

    workerThread=new QThread(this);

    connect(workerThread,&QThread::finished,this,&Widget::threadFinished);



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    Worker * worker=new Worker(); //at this point the worker starts in the thread where the GUI is in
    worker->moveToThread(workerThread);

    connect(workerThread,&QThread::started,worker,&Worker::doCounting);

    connect(worker,&Worker::currentCount,this,&Widget::currentCount);
    connect(worker,&Worker::countFinished,this,&Widget::countFinished);

    //since the instantiation of worker() does not have a parent, you have to ensure to kill the object when it is no longer used
    //when the thread finishes, delete the object
    connect(workerThread,&QThread::finished,worker,&Worker::deleteLater);

    workerThread->start();
}

void Widget::on_infoButton_clicked()
{
    qDebug()<<"Worker Counting thread is still running: "<<workerThread->isRunning();
}

void Widget::countFinished()
{
 qDebug()<<"Counting finished in the Widget";
 workerThread->quit();
}

void Widget::currentCount(int count)
{
    ui->progressBar->setValue(count);
    ui->infoLabel->setText(QString::number(count));
}

void Widget::threadFinished()
{
    qDebug()<<" Thread is finished. Thread: "<<thread();
    qDebug()<<" Thread is finished. Current thread :"<<QThread::currentThread();
}
