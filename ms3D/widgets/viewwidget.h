#ifndef MAINVIEWWIDGET_H
#define MAINVIEWWIDGET_H


#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMouseEvent>
#include <QPoint>
#include <QVector3D>
#include <QQuaternion>
#include <QtGui/QOpenGLFunctions_3_3_Core>
#include <math.h>
#include <QMessageBox>

#include "gameObjectComponents/mesh.h"
#include "gameObjectComponents/texture.h"
//#include "gameObject/graphicobject.h"
//#include "GUI/tooltabinfobox.h"
//#include "mathPrimitives/vertex.h"
//#include "gameObject/editabelObjects/editabelgameobject.h"
//#include "gameObject/editabelObjects/editabelgraphicobject.h"



class viewWidget: public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
     Q_OBJECT
public:
    viewWidget(QWidget *parent=0);
    ~viewWidget();
    void addMesh(mesh *model);
    void removeModel(mesh *model);
    void keyPressed(int key);
    void setDistance(float distance);
    float getDistance();
    void deleteAll();

protected:
    void updateView();
    void initializeGL();
    void resizeGL();
    void paintGL();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void angleXInc(int dir);
    void angleYInc(int dir);

    QWidget *parent;//указатель на родителя
    QOpenGLShaderProgram *sProgram;
    GLuint vertexArray,textureArray,indicesArray;//массивы координат вершин, текстурных координат и индексов
    QMatrix4x4 matrix;
    bool loaded;
    int angleX,angleY;//углы вращения
    int mPosX,mPosY;//предыдущая позиция курсора мыши
    float distance;
    float moveX,moveY;//смещения
    QVector<mesh*> modelsArray;
    QVector<texture*> *texturesVector;


};



#endif // MAINVIEWWIDGET_H
