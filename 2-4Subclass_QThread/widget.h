#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <workerthread.h>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void currentCount(int value);

    void on_startButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::Widget *ui;
    Workerthread * workerthread;
};
#endif // WIDGET_H
