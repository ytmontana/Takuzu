#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>

class Square : public QPushButton
{
    Q_OBJECT
public:
    Square(QWidget *parent, int i, int color);
    ~Square();
    int getColor();
    int getIndex();
    void decrementeClick();
    void incrementeClick();
private:
    int _color;
    bool _protect;
    int _index;
    int _numberOfClick;
public slots:
    void ChangeColor();
signals:
    void sendIndex();
};

#endif // SQUARE_H
