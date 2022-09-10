#include "timer.h"

#include <QDebug>

Timer::Timer(QWidget *parent)
    :QWidget(parent)
{
    start = time(NULL);
    current = time(NULL);
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), parent, SLOT(UpdateTime()));
    connect(_timer, SIGNAL(timeout()), this, SLOT(UpdateLabel()));
    _timer->start(1000);
    _chrono = new QLabel("Time : " + QString::number(0), this);
    _chrono->setMinimumWidth(300);
    _chrono->setFont(QFont("Arial", 20, QFont::Bold));
}

Timer::~Timer()
{

}
void Timer::UpdateLabel()
{
    current = time(NULL);
    int time = current - start;
    qDebug() << QString::number(time);
    if (time > 60) {
        _chrono->setText("Time : " + QString::number(time/60) +":" +QString::number(time%60));
    }  else {
        _chrono->setText("Time : " + QString::number(0) +":"+ QString::number(time));
    }
}

int Timer::getTime()
{
    current = time(NULL);
    return current - start;
}
