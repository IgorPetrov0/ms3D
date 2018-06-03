#ifndef MESH_H
#define MESH_H

#include "defines.h"
#include "msArray.h"

class mesh
{
public:
    mesh();
    const vertexCoordinates* getVertexesPointer();
    arraySize getVertexArraySize();

protected:
    msArray<vertexCoordinates> *vertexArray;

};

#endif // MESH_H
