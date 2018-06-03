#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QVector3D>
#include "gameObjectComponents/mesh.h"
#include "gameObjectComponents/phythicobject.h"

class gameObject
{
public:
    gameObject();
    ~gameObject();


protected:
    QVector3D position;
    QVector3D rotation;
    QVector3D scale;

    mesh *objectMesh;
    phythicObject *objectPhythic;


};

#endif // GAMEOBJECT_H
