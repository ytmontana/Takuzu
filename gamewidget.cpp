#include "gamewidget.h"
#include <QDebug>

GameWidget::GameWidget(QWidget *parent, int size, QString level)
    :QWidget(parent)
{
    _vlayout = new QVBoxLayout(this);
    _size = size;
    _level = level;
    _numberOfRounds = 0;
    _numberOfUndo = 0;
    map = new int[_size*_size];

    _fileManager = new FileManager(_size, _level);
    _fileManager->read();
    this->setLayout(_vlayout);

    _timerLayout = new QHBoxLayout(this);
    this->setLayout(_timerLayout);
    _timer = new Timer(this);
    _timerLayout->addWidget(_timer);
    _vlayout->addLayout(_timerLayout);

    _historyLayout = new QHBoxLayout(this);
    this->setLayout(_historyLayout);
    _undo = new UndoButton(this);
    _historyLayout->addWidget(_undo);
    _vlayout->addLayout(_historyLayout);

    for (int i = 0; i < size + 2; ++i) {
        QHBoxLayout* _hlayout = new QHBoxLayout(this);
        for (int j = 0; j < size + 2; ++j) {
            if ( j < _size && i < _size) {
                Square* s = new Square(this, i*_size+j, _fileManager->getMapColor(i*_size+j));
                connect(s, SIGNAL(clicked()), s, SLOT(ChangeColor()));
                connect(s, SIGNAL(clicked()), _undo, SLOT(pushElement()));
                _grid.append(s);
                map[i*_size+j] = _grid[i*_size+j]->getColor();
                _hlayout->addWidget(s);
            } else if (i == _size + 1 && j < _size) {
                FractionLabel* s = new FractionLabel(this, _size, 1);
                _hblack.append(s);
                _hlayout->addWidget(s);
            } else if (j == _size && i < _size) {
                FractionLabel* s = new FractionLabel(this, _size, 2);
                _vwhite.append(s);
                _hlayout->addWidget(s);
            } else if (j == _size + 1 && i < _size) {
                FractionLabel* s = new FractionLabel(this, _size, 1);
                _vblack.append(s);
                _hlayout->addWidget(s);
            } else if (i == _size && j < _size) {
                FractionLabel* s = new FractionLabel(this, _size, 2);
                _hwhite.append(s);
                _hlayout->addWidget(s);
            } else {
                QLabel* s = new QLabel("");
                _hlayout->addWidget(s);
            }
        }
        _vlayout->addLayout(_hlayout);
    }
    VUpdate();
    HUpdate();
    createConnection();
    connect(_undo, SIGNAL(clicked()), this, SLOT(previousPlacement()));
    connect(this, SIGNAL(GG()), parent, SLOT(printScore()));
}

void GameWidget::createConnection()
{
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            connect(_grid[i*_size+j], SIGNAL(clicked()), this, SLOT(evaluatePlacement()));
        }
    }
}


GameWidget::~GameWidget()
{

}

int GameWidget::getSize() {
    return _size;
}

int GameWidget::getNumberOfRounds() {
    return _numberOfRounds;
}

int GameWidget::getNumberOfUndo() {
    return _numberOfUndo;
}

QString GameWidget::getLevel() {
    return _level;
}

int  GameWidget::getTime() {
    return _timer->getTime();
}

void GameWidget::evaluatePlacement()
{
    Square *button = dynamic_cast<Square *>(sender());
    button->incrementeClick();
    ++_numberOfRounds;
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            map[i*_size+j] = _grid[i*_size+j]->getColor();
        }
    }
    VCheck(button->getIndex()%_size);
    HCheck(button->getIndex()/_size);
    VUpdate();
    HUpdate();

}

void GameWidget::previousPlacement()
{
    int index = _undo->popElement();
    if (index >= 0) {
        ++_numberOfUndo;
        _grid[index]->decrementeClick();
        _grid[index]->decrementeClick();
        _grid[index]->ChangeColor();
        _grid[index]->incrementeClick();
        map[index] = _grid[index]->getColor();
        VCheck(index%_size);
        HCheck(index/_size);
        VUpdate();
        HUpdate();
    }
}

void GameWidget::VUpdate() {
    int countBlack, countWhite;
    for (int row = 0; row < _size; ++row) {
        countBlack = 0, countWhite = 0;
        for (int column = 0; column < _size; ++column) {
            switch(map[row *_size+column]) {
                case 1:
                    ++countBlack;
                    break;
                case 2:
                    ++countWhite;
                    break;
                default:
                    break;
            }

            if ((countWhite == countBlack && countBlack == _size/2)&&(_vwhite[row]->getState() && _vblack[row]->getState())) {
                _vblack[row]->Update(countBlack, true);
                _vwhite[row]->Update(countWhite, true);
            } else {
                _vblack[row]->Update(countBlack, false);
                _vwhite[row]->Update(countWhite, false);
            }
        }

    }
}
void GameWidget::HUpdate() {
    int countBlack, countWhite;
    for (int column = 0; column < _size; ++column){
        countBlack = 0, countWhite = 0;
        for  (int row = 0; row < _size; ++row) {
            switch(map[row*_size+column]) {
                case 1:
                    ++countBlack;
                    break;
                case 2:
                    ++countWhite;
                    break;
                default:
                    break;
            }

            if ((countWhite == countBlack && countBlack == _size/2)&&(_hwhite[column]->getState() && _hblack[column]->getState())) {
                _hblack[column]->Update(countBlack, true);
                _hwhite[column]->Update(countWhite, true);
            } else {
                _hblack[column]->Update(countBlack, false);
                _hwhite[column]->Update(countWhite, false);
            }
        }
    }
    WinCheck();
}

void GameWidget::printMap() {
    for (int i = 0; i < _size; ++i) {
        qDebug() << map[i*_size] << map[i*_size+1] << map[i*_size+2] << map[i*_size+3] << map[i*_size+4] << map[i*_size+5];
    }
}

void GameWidget::HCheck(int row) {
    bool alreadyDetected = false;
    int column = 1;
    while (column < _size-1 && !alreadyDetected) {
        if (map[row*_size+column] != 0) {
            if ((map[row*_size+(column-1)] == map[row*_size+column])&&(map[row*_size+column] == map[row*_size+(column+1)])) {
                qDebug() << "black" << row << column << _vblack[row]->getState();
                qDebug() << "white" << row << column << _vwhite[row]->getState();
                alreadyDetected = true;
                switch(map[row*_size+column]) {
                    case 1:
                        _vblack[row]->PlacementCheck(false);
                        break;
                    case 2:
                        _vwhite[row]->PlacementCheck(false);
                        break;
                    default:
                        break;
                }
            } else {
                _vblack[row]->PlacementCheck(true);
                _vwhite[row]->PlacementCheck(true);
            }
        }
        column++;
    }
}

void GameWidget::VCheck(int column) {
    bool alreadyDetected = false;
    int row = 1;
    while (row < _size-1 && !alreadyDetected) {
        if (map[row*_size+column] != 0) {
            if ((map[(row-1)*_size+column] == map[row*_size+column])&&(map[row*_size+column] == map[(row+1)*_size+column])) {
                qDebug() << "black" << row << column << _hblack[row]->getState();
                qDebug() << "white" << row << column << _hwhite[row]->getState();
                alreadyDetected = true;
                switch(map[row*_size+column]) {
                    case 1:
                        _hblack[column]->PlacementCheck(false);
                        break;
                    case 2:
                        _hwhite[column]->PlacementCheck(false);
                        break;
                    default:
                        break;
                }
            } else {
                _hblack[column]->PlacementCheck(true);
                _hwhite[column]->PlacementCheck(true);
            }
        }
        row++;
    }
}

void GameWidget::WinCheck() {
    int count = 0;
    for(int i = 0; i < _size; ++i) {
        if (_hblack[i]->getFinish()) {
            count++;
        }
        if (_vblack[i]->getFinish()) {
            count++;
        }
    }
    if (count == 2*_size) {
        emit GG();
    }
}
