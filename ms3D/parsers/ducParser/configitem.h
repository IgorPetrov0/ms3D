#ifndef CONFIGITEM_H
#define CONFIGITEM_H

#include <QByteArray>
#include <QString>
#include <qdatastream.h>


enum ducType{
    DUC_INT,
    DUC_FLOAT,
    DUC_STRING,
    DUC_VECTOR3D
};



class configItem
{
public:
    configItem(int value,int rangeMin=0, int rangeMax=0, QString description=0);
    configItem();
    ~configItem();

    QString varName;
    QByteArray value;
    QByteArray rangeMinim;
    QByteArray rangeMaxim;
    int type;//тип
    QString description;//описалово

    bool isValid();
    void serialise(QDataStream *str);


protected:




};

#endif // CONFIGITEM_H
