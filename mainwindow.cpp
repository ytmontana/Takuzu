#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Takuzu");
    setGeometry(500, 50, 1000, 800);

    _stack = new QStackedWidget(this);

    _settingsWidget = new SettingsWidget(this);
    _stack->addWidget(_settingsWidget);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(_stack);
    setLayout(layout);
    setCentralWidget(_stack);
}

MainWindow::~MainWindow()
{

}

void MainWindow::playGame()
{
    _size = _settingsWidget->getSize();
    _level = _settingsWidget->getLevel();
    _gameWidget = new GameWidget(this, _size, _level);
    _stack->addWidget(_gameWidget);
    _stack->setCurrentWidget(_gameWidget);
    setCentralWidget(_stack);
}

void MainWindow::printScore()
{
    _scoreWidget = new ScoreWidget(this, _gameWidget->getSize(), _gameWidget->getLevel(), _gameWidget->getNumberOfRounds(), _gameWidget->getNumberOfUndo(), _gameWidget->getTime());
    _stack->addWidget(_scoreWidget);
    _stack->setCurrentWidget(_scoreWidget);
    setCentralWidget(_stack);
}

void MainWindow::setGame()
{
    _stack->setCurrentWidget(_settingsWidget);
    setCentralWidget(_stack);
}
