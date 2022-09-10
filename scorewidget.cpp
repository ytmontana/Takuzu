#include "scorewidget.h"

ScoreWidget::ScoreWidget(QWidget *parent, int size, QString level, int numberOfRounds, int numberOfUndo, int time)
    :QWidget(parent)
{
    QString style = "QComboBox QAbstractItemView { border: 1px solid gray }";
    title = new QLabel("Takuzu - Ecran des scores", this);
    title->setFont(QFont("Arial", 24, QFont::Bold));
    title->setAlignment(Qt::AlignCenter);

    label1 = new QLabel("Size of the grid :", this);
    label1->setFont(QFont("Arial", 14, QFont::Bold));

    result1 = new QLabel(QString::number(size), this);
    result1->setFont(QFont("Arial", 14, QFont::Bold));
    result1->setAlignment(Qt::AlignCenter);

    label2 = new QLabel("Level of difficulty :", this);
    label2->setFont(QFont("Arial", 14, QFont::Bold));

    result2 = new QLabel(level, this);
    result2->setFont(QFont("Arial", 14, QFont::Bold));
    result2->setAlignment(Qt::AlignCenter);

    label3 = new QLabel("Number of rounds :", this);
    label3->setFont(QFont("Arial", 14, QFont::Bold));

    result3 = new QLabel(QString::number(numberOfRounds), this);
    result3->setFont(QFont("Arial", 14, QFont::Bold));
    result3->setAlignment(Qt::AlignCenter);

    label4 = new QLabel("Number of undo :", this);
    label4->setFont(QFont("Arial", 14, QFont::Bold));

    result4 = new QLabel(QString::number(numberOfUndo), this);
    result4->setFont(QFont("Arial", 14, QFont::Bold));
    result4->setAlignment(Qt::AlignCenter);

    label5 = new QLabel("Time :", this);
    label5->setFont(QFont("Arial", 14, QFont::Bold));

    result5 = new QLabel(QString::number(time) + " s", this);
    result5->setFont(QFont("Arial", 14, QFont::Bold));
    result5->setAlignment(Qt::AlignCenter);

    pushButtonQuit = new QPushButton("Quit", this);
    pushButtonQuit->setGeometry(850, 500, 160, 30);
    pushButtonQuit->setFont(QFont("Arial", 14, QFont::Bold));

    pushButtonReplay = new QPushButton("Replay", this);
    pushButtonReplay->setGeometry(850, 500, 160, 30);
    pushButtonReplay->setFont(QFont("Arial", 14, QFont::Bold));

    layout = new QFormLayout(this);
    layout->addRow(title);
    layout->addRow(label1, result1);
    layout->addRow(label2, result2);
    layout->addRow(label3, result3);
    layout->addRow(label4, result4);
    layout->addRow(label5, result5);
    layout->addRow(pushButtonReplay);
    layout->addRow(pushButtonQuit);

    connect(pushButtonReplay, SIGNAL(clicked()), parent, SLOT(setGame()));
    connect(pushButtonQuit, SIGNAL(clicked()), parent, SLOT(destroy()));
}
ScoreWidget::~ScoreWidget()
{

}
