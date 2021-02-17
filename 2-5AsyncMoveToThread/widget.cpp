#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<"UI is running in thread: "<<QThread::currentThread();
    myThread=new QThread(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    Worker * myWorker=new Worker(); //do not use a parent in the argument, instead handle the memory for yourself

    myWorker->moveToThread(myThread);

    connect(myThread,&QThread::started,myWorker,&Worker::doWork);
    connect(myThread,&QThread::finished,myWorker,[=]()
    {
        qDebug()<<"Thread finished";
    });

    //clean the memory after completing the thread
    connect(myThread,&QThread::finished,myWorker,&Worker::deleteLater);

    myThread->start();

}

void Widget::on_stopButton_clicked()
{
    myThread->exit();
}

void Widget::on_infoButton_clicked()
{
    qDebug()<<"Thread is running: "<<myThread->isRunning();
}
