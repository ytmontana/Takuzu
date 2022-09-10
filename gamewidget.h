#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>


#include "fractionlabel.h"
#include "square.h"
#include "timer.h"
#include "filemanager.h"
#include "undobutton.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent, int size, QString level);
    ~GameWidget();
    void createConnection();
    void setMapColor();
    void VUpdate();
    void HUpdate();
    void HCheck(int row);
    void VCheck(int column);
    void WinCheck();
    int getSize();
    QString getLevel();
    int getNumberOfRounds();
    int getNumberOfUndo();
    int getTime();
signals:
    void GG();
public slots:
    void evaluatePlacement();
    void previousPlacement();
private:
    QList<FractionLabel*> _hblack, _hwhite, _vblack, _vwhite;
    QList<Square*> _grid;
    QVBoxLayout* _vlayout;
    QHBoxLayout* _historyLayout,* _timerLayout;
    Timer* _timer;
    UndoButton* _undo;
    FileManager *_fileManager;
    int _size;
    QString _level;
    int* map;
    int _numberOfRounds;
    int _numberOfUndo;
    void printMap();
};

#endif // GAMEWIDGET_H
