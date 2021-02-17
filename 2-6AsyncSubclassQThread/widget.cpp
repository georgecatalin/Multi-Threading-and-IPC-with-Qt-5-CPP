#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myWorkerThread=new WorkerThread(this);

    connect(myWorkerThread,&WorkerThread::finished,[=]()
    {
        qDebug()<<"Thread is finished.";
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    myWorkerThread->start();
}

void Widget::on_stopButton_clicked()
{
  myWorkerThread->quit();
}

void Widget::on_infoButton_clicked()
{
qDebug()<<"Thread is running : "<<myWorkerThread->isRunning();
}
