#ifndef MATERIAL_H
#define MATERIAL_H

#include <QString>
#include <QVector>
#include <qopengl.h>

class material
{
public:
    material();
    ~material();
    void setName(QString name);
    void setFacesCount(int count);//устанавливает кол-во треугольников
    void setVertexIndicesArray(int *array);
    void setTextureIndicesArray(int *array);
    void setNormalsIndicesArray(int *array);
    int getFacesCount();//возвращает количество треугольников
    QString getName();
    int *getVertexIndicesArrayPointer();
    int *getNormalsIndicesArrayPointer();
    int *getTextureIndicesArrayPointer();

protected:
    QString name;
    int *vertexIndicesArray;//массив вершинных индексов
    int *textureIndicesArray;//массив текстурных индексов
    int *normalsIndicesArray;//массив индексов нормалей
    //количество треугольников
    int facesCount;


    
};

#endif // MATERIAL_H
