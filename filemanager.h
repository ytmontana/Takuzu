#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include <QApplication>

class FileManager
{
private:
    QString _filename;
    int _size;
    QString _level;
    int *map;
public:
    FileManager(int size, QString level);
    void read();
    void createMap(QString contenu);
    int getMapColor(int index);
};

#endif // FILEMANAGER_H
