#ifndef PARSEROBJ_H
#define PARSEROBJ_H

#include <QFile>
#include <QVector>
#include "parsers/material.h"
#include "parsers/baseparser.h"

class parserOBJ : public baseParser
{

public:
    parserOBJ();
    ~parserOBJ();
    bool readFile(QString fileName);
    void getAllMaterials(QVector<material*> *matArray);//выдает все материалы, которые есть в списке

protected:
    bool parsObj(QFile *file);
    //bool readNumSring(QString *string, unsigned char n,QVector<QString> *outVector);
    bool readNumbers(QString *string, QVector<float> *outVector);//чтение чисел из строки
    void deleteObject();//удаление объекта с проверкой




};

#endif // PARSEROBJ_H
