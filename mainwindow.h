#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStackedWidget>

#include "gamewidget.h"
#include "historywidget.h"
#include "settingswidget.h"
#include "scorewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget *_stack;
    QVBoxLayout* _mainWindow;
    SettingsWidget* _settingsWidget;
    GameWidget* _gameWidget;
    ScoreWidget* _scoreWidget;
    int _size;
    QString _level;
public slots:
   void playGame();
   void printScore();
   void setGame();
};
#endif // MAINWINDOW_H
