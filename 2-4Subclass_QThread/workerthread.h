#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QDebug>
#include <QVariant>


class Workerthread : public QThread
{
    Q_OBJECT
public:
    explicit Workerthread(QObject *parent = nullptr);
    ~ Workerthread() override;

signals:
  void currentCount(int value);

    // QThread interface
protected:
    void run() override;
};

#endif // WORKERTHREAD_H
