#include "historywidget.h"

HistoryWidget::HistoryWidget(QWidget *parent)
    :QWidget(parent)
{
    _layout = new QHBoxLayout(this);
    this->setLayout(_layout);
    _undo = new QPushButton("Undo");
    _redo = new QPushButton("Redo");
    _layout->addWidget(_undo);
    _layout->addWidget(_redo);
}

HistoryWidget::~HistoryWidget()
{

}
