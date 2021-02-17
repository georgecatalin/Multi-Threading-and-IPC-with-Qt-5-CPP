#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "worker.h"
#include <QThreadPool>


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

    void on_infoButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
