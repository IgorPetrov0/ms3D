#include "material.h"

material::material()
{
    vertexIndicesArray=NULL;
    textureIndicesArray=NULL;
    normalsIndicesArray=NULL;

    facesCount=0;
}
//////////////////////////////////////
material::~material()
{
    name.clear();
    if(vertexIndicesArray!=NULL){
        delete []vertexIndicesArray;
    }
    if(textureIndicesArray!=NULL){
        delete []textureIndicesArray;
    }
    if(normalsIndicesArray!=NULL){
        delete []normalsIndicesArray;
    }
}
////////////////////////////////////////
void material::setName(QString name){
    this->name=name;
}
/////////////////////////////////////////////////////
void material::setVertexIndicesArray(int *array){
    if(vertexIndicesArray!=NULL){
        delete []vertexIndicesArray;
    }
    vertexIndicesArray=array;
}
////////////////////////////////////////////////////////
void material::setTextureIndicesArray(int *array){
    if(textureIndicesArray!=NULL){
        delete []textureIndicesArray;
    }
    textureIndicesArray=array;
}
//////////////////////////////////////////////////////////
void material::setNormalsIndicesArray(int *array){
    if(normalsIndicesArray!=NULL){
        delete []normalsIndicesArray;
    }
    normalsIndicesArray=array;
}
////////////////////////////////////////////////////////////
void material::setFacesCount(int count){
    facesCount=count;
}
/////////////////////////////////////////////////////////////
int material::getFacesCount(){
    return facesCount;
}
///////////////////////////////////////////////////////////////////////////////////
int *material::getNormalsIndicesArrayPointer(){
    return normalsIndicesArray;
}
///////////////////////////////////////////////////////////////////////////////////
int *material::getVertexIndicesArrayPointer(){
    return vertexIndicesArray;
}
///////////////////////////////////////////////////////////////////////////////////
int *material::getTextureIndicesArrayPointer(){
    return textureIndicesArray;
}
//////////////////////////////////////////////////////////////////////////////////
QString material::getName(){
    return name;
}
//////////////////////////////////////////////////////////////////////////////////


