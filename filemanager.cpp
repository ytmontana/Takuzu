#include "filemanager.h"

#include <QDebug>
#include <QFile>



FileManager::FileManager(int size, QString level)
{
    _level = level;
    _size = size;
    _filename = QString::fromStdString("C:\\Users\\pinse\\Desktop\\Takuzu\\" + std::to_string(_size) + "_" + _level.toUtf8().constData() + ".txt");
    map = new int[_size*_size];
}

void FileManager::read()
{
    srand( (unsigned)time(NULL) );

    QFile file(_filename);
    QString contenu;

    if(!file.exists()) {
        qDebug() << "Le fichier n'existe pas";
    } else {
        bool result = file.open(QIODevice::ReadOnly);
        if(!result) {
            qDebug() << "Impossible d'ouvrir le fichier";
        } else {
            QTextStream reader(&file);
            int numberOfMap;
            reader >> numberOfMap;
            int i = 0;
            int randomInt = rand();
            while( i < (randomInt % numberOfMap) +1) {
                contenu = reader.readLine();
                ++i;
            }
            createMap(contenu);
        }
    }
    file.close();
}


void FileManager::createMap(QString contenu)
{
    int numberOfSquare = _size*_size;
    for (int i = 0; i < numberOfSquare; ++i) {
        switch(contenu.toUtf8().constData()[i]) {
            case 'B' :
                map[i] = 1;
                break;
            case 'W' :
                map[i] = 2;
                break;
            default:
                map[i] = 0;
                break;
        }
    }
}

int FileManager::getMapColor(int index)
{
    return map[index];
}
