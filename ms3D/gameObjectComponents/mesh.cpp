#include "mesh.h"

mesh::mesh()
{
    vertexArray=NULL;
}
//////////////////////////////////////////////////////////
const vertexCoordinates *mesh::getVertexesPointer(){
    return vertexArray->getArrayPointer();
}
//////////////////////////////////////////////////////////
arraySize mesh::getVertexArraySize(){
    return vertexArray->getSize();
}
//////////////////////////////////////////////////////////
