#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QFormLayout>

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    SettingsWidget(QWidget *parent);
    ~SettingsWidget();
    int getSize();
    QString getLevel();
private :
   QLabel *label1, *label2;
   QFormLayout *layout;
   QComboBox *sizeList, *levelList;
   QPushButton *pushButtonPlay;
   int _size;
   QString _level;

};

#endif // SETTINGSWIDGET_H
