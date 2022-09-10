#include "fractionlabel.h"

FractionLabel::FractionLabel(QWidget *parent, int size, int color)
    : QLabel(parent)
{
    _size = size;
    _value = size/2;
    _color = color;
    _state = true;
    _finish = false;
    switch (_color) {
        case 1:
            setStyleSheet("background-color : blue;");
            setText(QString::number(_value));
            setAlignment(Qt::AlignCenter);
            break;
        case 2:
            setStyleSheet("background-color : red");
            setText(QString::number(_value));
            setAlignment(Qt::AlignCenter);
            break;
        default:
            break;
    }
    setFont(QFont("Arial", 14, QFont::Bold));
}

void FractionLabel::PlacementCheck(bool valid) {
    if (!valid) {
        setStyleSheet("background-color : yellow;");
        _state = false;
    } else {
        if(!_state) {
            _state = true;
            switch (_color) {
                case 1:
                    setStyleSheet("background-color : blue;");
                    break;
                case 2:
                    setStyleSheet("background-color : red");
                    break;
                default:
                    break;
            }
        }
    }
}

void FractionLabel::Update(int value, bool finish) {
    if (finish) {
        _finish = true;
        setStyleSheet("background-color : green;");
        switch(_color) {
        case 1:
            setText("K");
            setAlignment(Qt::AlignCenter);
            break;
        case 2:
            setText("O");
            setAlignment(Qt::AlignCenter);
            break;
        default:
            break;
        }
    } else {
        _finish = false;
        _value = _size/2 - value;
        setText(QString::number(_value));
        if(_state) {
            switch (_color) {
                case 1:
                    setStyleSheet("background-color : blue;");
                    break;
                case 2:
                    setStyleSheet("background-color : red");
                    break;
                default:
                    break;
            }
        }
    }
}

bool FractionLabel::getFinish() {
    return _finish;
}

bool FractionLabel::getState() {
    return _state;
}

FractionLabel::~FractionLabel()
{

}
