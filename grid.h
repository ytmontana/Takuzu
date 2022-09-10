#ifndef GRID_H
#define GRID_H

#include <QWidget>
#include <QVBoxLayout>

#include "square.h"

class Grid : public QWidget
{
    Q_OBJECT
public:
    Grid(QWidget *parent, int size, int alea);
    ~Grid();
private:
    QList<Square*> _grid;
    QVBoxLayout* _vlayout;
    int _size;
};

#endif // GRID_H
