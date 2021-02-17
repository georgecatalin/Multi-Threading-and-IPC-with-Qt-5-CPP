#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QDebug>
#include "worker.h"

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
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::Widget *ui;
    QThread * myThread;
};
#endif // WIDGET_H
