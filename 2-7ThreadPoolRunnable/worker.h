#ifndef WORKER_H
#define WORKER_H

#include <QRunnable>
#include <QDebug>
#include <QThread>

class Worker : public QRunnable
{

public:
    explicit Worker();
    ~ Worker();


    // QRunnable interface
public:
    void run() override;
};

#endif // WORKER_H
