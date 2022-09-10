#ifndef FRACTIONLABEL_H
#define FRACTIONLABEL_H

#include <QLabel>

#include "square.h"

class FractionLabel : public QLabel
{
    Q_OBJECT
public:
    FractionLabel(QWidget *parent, int size, int color);
    ~FractionLabel();
    void Update(int value, bool finish);
    void PlacementCheck(bool valid);
    bool getFinish();
    bool getState();
private:
    int _size;
    int _value;
    int _color;
    bool _state;
    bool _finish;
};

#endif // FRACTIONLABEL_H
