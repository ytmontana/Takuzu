#ifndef UNDOBUTTON_H
#define UNDOBUTTON_H

#include <QPushButton>
#include <stack>
#include "square.h"

class UndoButton : public QPushButton
{
    Q_OBJECT
public:
    UndoButton(QWidget *parent);
    ~UndoButton();
    int popElement();
public slots:
    void pushElement();
private:
    std::stack<int> _indexStack;
};

#endif // UNDOBUTTON_H
