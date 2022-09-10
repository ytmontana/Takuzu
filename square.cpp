#include "square.h"

#include <QDebug>

Square::Square(QWidget *parent, int index, int color)
    :QPushButton(parent)
{
    _color = color;
    _numberOfClick = 0;
    _index = index;
    if (_color == 0) {
        setStyleSheet("background-color : gray");
        _protect = false;
    } else if (_color == 1) {
        setStyleSheet("background-color : blue");
        _protect = true;
    } else {
        setStyleSheet("background-color : red");
        _protect = true;
    }
}

void Square::ChangeColor()
{
    if(!_protect) {
        if (_numberOfClick == -1) {
            setStyleSheet("background-color : gray");
            _color = 0;
        } else if (_color == 0 || _color == 2) {
            setStyleSheet("background-color : blue");
            _color = 1;
        } else {
            setStyleSheet("background-color : red");
            _color = 2;
        }
    }
}




Square::~Square()
{

}

int Square::getColor()
{
    return _color;
}

int Square::getIndex()
{
    return _index;
}

void Square::decrementeClick()
{
    --_numberOfClick;
}
void Square::incrementeClick()
{
    ++_numberOfClick;
}
