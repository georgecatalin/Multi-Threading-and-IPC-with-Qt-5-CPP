#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<"The UI is running in this thread: "<<QThread::currentThread();

    workerthread=new Workerthread(this);

    connect(workerthread,&Workerthread::currentCount,this,&Widget::currentCount);

    connect(workerthread,&QThread::started,[=]()
    {
        qDebug()<<"Thread has started.";
    });

    connect(workerthread,&QThread::finished,[=]()
    {
        qDebug()<<"Thread has finished";
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::currentCount(int value)
{
  ui->progressBar->setValue(value);
  ui->infoLabel->setText(QString::number(value));
}


void Widget::on_startButton_clicked()
{
    workerthread->start();
}

void Widget::on_infoButton_clicked()
{
    qDebug()<<" The Workerthread is running :"<<workerthread->isRunning();
}
