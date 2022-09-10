#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QTime>
#include <QWidget>
#include <QLabel>
#include <ctime>

class Timer : public QWidget
{
    Q_OBJECT
public:
    Timer(QWidget *parent);
    ~Timer();
    int getTime();
private:
    QLabel* _chrono;
    QTimer* _timer;
    time_t start, current;
public slots:
    void UpdateLabel();
};

#endif // TIMER_H
