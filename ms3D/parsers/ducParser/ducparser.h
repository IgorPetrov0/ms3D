#ifndef DUCPARSER_H
#define DUCPARSER_H

#include <QString>
#include <QFile>
#include <qdatastream.h>
#include <QMessageBox>
#include <QObject>
#include <QVector>
#include "configitem.h"



class ducParser:QObject
{

    Q_OBJECT

public:
    ducParser();
    ~ducParser();


    bool newFile(QString fileName);
    bool atEnd();

    void writeInt(QString varName, int type, int value, int rangeMin=0, int rangeMax=0, QString description=0);
    void writeFloat(QString varName, int type, float value, float rangeMin=0, float rangeMax=0, QString description=0);
    void writeString(QString varName, int type, QString value,int rangeMin=0, int rangeMax=0, QString fescription=0);
    void writeRawData(configItem *item);//пишет сырые данные

    //при чтении просто вызываем их по порядку. итератор есть в str
    //если труктура configItem не нужна, то можное ее не создавать и не получать
    //varName - для обработки ошибок. тоже опционально
    bool readVar(int *var, QString *varName=NULL, configItem *item=NULL);
    bool readVar(float *var, QString *varName=NULL, configItem *item=NULL);
    bool readVar(QString *var,QString *varName=NULL, configItem *item=NULL);
    bool readRawData(configItem *item);//читает сырые данные

    void saveConfigItemaArray();
    bool loadFile(QString fileName);
    void closeFile();


    void addNewItem(configItem *item);



protected:

    QFile *file;
    QDataStream *str;
    bool isOk;



    int version;


};

#endif // DUCPARSER_H
