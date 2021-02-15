#include "widget.h"
#include "ui_widget.h"


void counting1(int countupto)
{
    for (int i{0};i<countupto ;i++ )
    {
        qDebug()<<"Counting "<<i<<" in current thread "<<QThread::currentThread();
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<"Main thread is "<<QThread::currentThread();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::count(int counter)
{
    for (int i{0};i<counter ;i++ )
    {
       qDebug()<<" Counting method called :"<<i<<" thread :"<<QThread::currentThread()<< " id: "<< QThread::currentThreadId()<<" Thread is running: "<< myThread->isRunning();

    }
}


void Widget::on_startButton_clicked()
{

    /* *** execute the following sequence to block the app *** */

//    for (int i{0};i<1000000 ;i++ )
//    {
//        qDebug()<<" Counting in the UI thread.";
//        qDebug()<<" Counting "<<i<<" thread "<<QThread::currentThread()<<" id: "<<QThread::currentThreadId();
//    }


    qDebug()<<"Clicked on the start button";

    // 1. Global function
    /*
    myThread=QThread::create(counting1,10000);
    */

    /* **************************
    // 2. Named lamda function
    auto countLambda=[=](int count)
    {
        for (int i{0};i<count ;i++ )
        {
         qDebug()<<"countLambda counting";
         qDebug()<<"Counting :"<<i<<" Thread :"<< QThread::currentThread()<<" ID : "<<QThread::currentThreadId();
        }
    };

    myThread=QThread::create(countLambda,10000);

    ******************************* */

    /* *********************************************************************************************************
    // 3. Non named lambda function
    myThread=QThread::create([=]()
    {
        for (int i{0};i<100000 ;i++ )
        {
        qDebug()<<"non named lambda function counting";
        qDebug()<<"Counting :"<<i<<" thread : "<<QThread::currentThread()<<" id :"<<QThread::currentThreadId();
        }

    });
    *********************************************************************************************************** */

    //4. Member class call for lambda function

    myThread=QThread::create([=](){
        count(10000);
    });


    /* ***  the caller acquires ownership of the returned QThread instance. Hence you gotta manage memory after it completes execution and so on *** */

    connect(myThread,&QThread::started,[=]()
    {
        qDebug()<<" The secondary thread just started.";
    });

    connect(myThread,&QThread::finished,[=]()
    {
        qDebug()<<" The secondary thread just finished.";
    });

    /* *** free the memory after completing the thread *** */
    connect(myThread,&QThread::finished,myThread,&QThread::deleteLater);

      myThread->start();
}
