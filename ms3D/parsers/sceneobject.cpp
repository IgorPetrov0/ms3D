#include "sceneobject.h"

sceneObject::sceneObject()
{
    vertexArray=NULL;
    texturesArray=NULL;
    normalsArray=NULL;
    vertexArraySize=0;
    normalsArraySize=0;
    texturesArraySize=0;
    vertexIndicesArraySize=0;

}
/////////////////////////////////////
sceneObject::~sceneObject()
{
    delete []vertexArray;
    delete []texturesArray;
    delete []normalsArray;
    for(int n=0;n!=materialsArray.size();n++){
        delete materialsArray.at(n);
    }
    materialsArray.clear();
}
//////////////////////////////////////
void sceneObject::setName(QString name){
    this->name=name;
}
//////////////////////////////////////////
void sceneObject::addMaterial(material *mat){
    materialsArray.append(mat);
}
//////////////////////////////////////////////////
int sceneObject::getMaterialsSize(){
    return materialsArray.size();
}
///////////////////////////////////////////////////
material *sceneObject::getMaterial(int index){
    if((index>=0)&(index<materialsArray.size())){
        return materialsArray.at(index);
    }
    return NULL;
}
///////////////////////////////////////////////////
void sceneObject::clear(){
    materialsArray.clear();
    delete []vertexArray;
    name.clear();
}
//////////////////////////////////////////////////////////////
int sceneObject::getVertexSize(){
    return vertexArraySize;
}
///////////////////////////////////////////////////////////////////
void sceneObject::addVertex(){
    //vertexArray.append(vertex);
}
//////////////////////////////////////////////////////////////////
float *sceneObject::getVertexArrayPointer(){
    return vertexArray;
}
//////////////////////////////////////////////////////////////////
void sceneObject::setVertexArray(float *array,int size){
    vertexArray=array;
    vertexArraySize=size;
}
/////////////////////////////////////////////////////////////////
void sceneObject::setNormalsArray(float *array, int size){
    normalsArray=array;
    normalsArraySize=size;
}
////////////////////////////////////////////////////////////////////
void sceneObject::setTexturesArray(float *array,int size){
    texturesArray=array;
    texturesArraySize=size;
}
////////////////////////////////////////////////////////////////////
int sceneObject::getFaces(){
    int count=0;
    for(int n=0;n!=materialsArray.size();n++){
        count+=materialsArray.at(n)->getFacesCount();
    }
    return count;
}

