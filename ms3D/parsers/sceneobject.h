#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <QString>
#include <QVector>
#include "parsers/material.h"


class sceneObject
{
public:
    sceneObject();
    ~sceneObject();
    void setName(QString name);
    void addMaterial(material *mat);
    void addVertex();
    void addNormal();
    void addTextCoord();
    

    //создание массивов
    void setVertexArray(float *array,int size);
    void setNormalsArray(float *array, int size);
    void setTexturesArray(float *array,int size);
    
    int getMaterialsSize();//возвращает количество материалов в объекте
    int getVertexSize();//возвращает количество вершин
    int getFaces();//считает количество полигонов во всех материалах
    
    float *getVertexArrayPointer();
    material *getMaterial(int index);//возвращает указатель на материал по индексу
    void clear();//выгрузка из памяти

protected:
    QString name;
    QVector<material*>materialsArray;
    float *vertexArray;//массив вершин
    float *normalsArray;//массив нормалей
    float *texturesArray;//массив текстурных координат
    //размеры соответствующих массивов
    int vertexArraySize;
    int normalsArraySize;
    int texturesArraySize;
    int vertexIndicesArraySize;







};

#endif // SCENEOBJECT_H
