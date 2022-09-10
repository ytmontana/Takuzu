#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QFormLayout>

class ScoreWidget : public QWidget
{
    Q_OBJECT
public:
    ScoreWidget(QWidget *parent, int size, QString level, int numberOfRounds, int numberOfUndo, int time);
    ~ScoreWidget();
private :
   QLabel *title, *label1, *label2, *result1, *result2, *label3, *label4, *result3, *result4,  *label5, *result5;
   QFormLayout *layout;
   QPushButton *pushButtonQuit, *pushButtonReplay;
};

#endif // SCOREWIDGET_H
