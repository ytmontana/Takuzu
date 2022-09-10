#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent)
    :QWidget(parent)
{
    QString style = "QComboBox QAbstractItemView { border: 1px solid gray }";

    label1 = new QLabel("Size of the grid :", this);
    label1->setFont(QFont("Arial", 14, QFont::Bold));

    sizeList = new QComboBox();
    sizeList->setFont(QFont("Arial", 14, QFont::Bold));
    sizeList->addItem("6x6", 6);
    sizeList->addItem("8x8", 8);
    sizeList->addItem("10x10", 10);

    label2 = new QLabel("Level of difficulty :", this);
    label2->setFont(QFont("Arial", 14, QFont::Bold));

    levelList = new QComboBox();
    levelList->setStyleSheet(style);
    levelList->setFont(QFont("Arial", 14, QFont::Bold));
    levelList->addItem("easy");
    levelList->addItem("hard");

    pushButtonPlay = new QPushButton("Play", this);
    pushButtonPlay->setGeometry(850, 500, 160, 30);
    pushButtonPlay->setFont(QFont("Arial", 14, QFont::Bold));

    layout = new QFormLayout(this);
    layout->addRow(label1, sizeList);
    layout->addRow(label2, levelList);
    layout->addRow(pushButtonPlay);


    connect(pushButtonPlay, SIGNAL(clicked()), parent, SLOT(playGame()));
}

SettingsWidget::~SettingsWidget()
{

}

int SettingsWidget::getSize() {
    if (sizeList->currentIndex() == 0){
        return 6;
    } else if (sizeList->currentIndex() == 1){
        return 8;
    } else {
        return 10;
    }
}

QString SettingsWidget::getLevel() {
    return levelList->currentText();
}
