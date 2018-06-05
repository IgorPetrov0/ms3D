#include "baseparser.h"

baseParser::baseParser()
{

}
//////////////////////////////////////////////////////
QString baseParser::getLastError(){
    QString tmp=lastError;
    lastError.clear();
    return tmp;
}
///////////////////////////////////////////////////////////////////
sceneObject* baseParser::getSceneObject(){
    //указатель на объект можно запросить только раз
    //кто запросил объект, тот и отвечает за его удаление
    sceneObject *tmp=object;
    object=NULL;//если указатель запрошен, то парсер его забывает
    return tmp;
}
