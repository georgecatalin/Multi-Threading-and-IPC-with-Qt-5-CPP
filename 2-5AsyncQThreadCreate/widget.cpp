#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<"The UI is running in this thread: "<< QThread::currentThread();

    // Use this sequence when starting out the QTimer object in the same thread as the main UI
    /*
    QTimer * myTimer=new QTimer();
    connect(myTimer,&QTimer::timeout,[=]()
    {
        qDebug()<<"The timer has timed out. It is running in thread: "<<QThread::currentThread();
    });

    myTimer->start(1000);
    */

    // Use this sequence when starting out the QTimer in a new thread than the one of the main UI

    myThread=QThread::create([=]()
    {
        QTimer * myTimer=new QTimer();
        connect(myTimer,&QTimer::timeout,[=]()
        {
         qDebug()<<"The timer has timed out. It is running in thread: "<<QThread::currentThread();
        });

        myTimer->start(1000);
    });

    connect(myThread,&QThread::started,[=]
    {
        qDebug()<<"The new thread just started.";
    });

    connect(myThread,&QThread::finished,[=]
    {
        qDebug()<<"The new thread just finished.";
    });

    /* !! QThread::create() does not create an event loop , hence it can not be used asynchronous classes like QTimer and QTcpSockets !!
    For this to run , you either need "MoveToThread" or "Subclass QThread" methods.
    */

    //myThread->start();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    myThread->start();
}
