#include "gameobject.h"

gameObject::gameObject()
{
    objectMesh = NULL;
    objectPhythic = NULL;
}
////////////////////////////////////////////////////////
gameObject::~gameObject(){
    if(objectMesh!=NULL){
        delete objectMesh;
    }
    if(objectPhythic!=NULL){
        delete objectPhythic;
    }
}
