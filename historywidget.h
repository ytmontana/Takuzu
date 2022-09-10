#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class HistoryWidget : public QWidget
{
    Q_OBJECT
public:
    HistoryWidget(QWidget *parent);
    ~HistoryWidget();
private:
    QHBoxLayout* _layout;
    QPushButton* _undo,* _redo;
};

#endif // HISTORYWIDGET_H
