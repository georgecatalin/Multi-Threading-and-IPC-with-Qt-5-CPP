#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QDebug>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = nullptr);
    ~ WorkerThread() override;

signals:


    // QThread interface
protected:
    void run() override;
};

#endif // WORKERTHREAD_H
