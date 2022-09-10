#include "grid.h"

Grid::Grid(QWidget *parent, int size, int alea)
    :QWidget(parent)
{
    _vlayout = new QVBoxLayout(this);

    this->setLayout(_vlayout);
    for (int i = 0; i < size; ++i) {
        QHBoxLayout* _hlayout = new QHBoxLayout(this);
        for (int j = 0; j < size; ++j) {
            Square* s = new Square(this, i*6+j);
            connect(s, SIGNAL(clicked()), s, SLOT(ChangeColor()));
            _grid.append(s);
            _hlayout->addWidget(s);
        }
        _vlayout->addLayout(_hlayout);
    }

}


Grid::~Grid()
{

}
