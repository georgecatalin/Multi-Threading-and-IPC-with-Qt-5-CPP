#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<"UI is running in the thread"<<QThread::currentThread();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    Worker * myWorker=new Worker();

    /*
       void QRunnable::setAutoDelete(bool autoDelete)

       Enables auto-deletion if autoDelete is true; otherwise auto-deletion is disabled.
       If auto-deletion is enabled, QThreadPool will automatically delete this runnable after calling run(); otherwise, ownership remains with the application programmer.
       Note that this flag must be set before calling QThreadPool::start(). Calling this function after QThreadPool::start() results in undefined behavior.
     * *******************************************************************************************
     * */


    myWorker->setAutoDelete(false);

    QThreadPool::globalInstance()->start(myWorker);

}

void Widget::on_infoButton_clicked()
{

}
