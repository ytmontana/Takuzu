#include "undobutton.h"

UndoButton::UndoButton(QWidget *parent)
    :QPushButton("Undo", parent)
{
    setFont(QFont("Arial", 14, QFont::Bold));
}

UndoButton::~UndoButton()
{

}

void UndoButton::pushElement()
{
    Square *button = dynamic_cast<Square *>(sender());
    _indexStack.push(button->getIndex());
}

int UndoButton::popElement()
{
    if(!_indexStack.empty()) {
        int index = _indexStack.top();
        _indexStack.pop();
        return index;
    } else {
        return -1;
    }

}



