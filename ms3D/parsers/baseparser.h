#ifndef BASEPARSER_H
#define BASEPARSER_H

#include <QString>
#include <QObject>
#include "parsers/sceneobject.h"

class baseParser : QObject
{
    Q_OBJECT
public:
    baseParser();
    QString getLastError();
    sceneObject* getSceneObject();


protected:
    QString lastError;
    sceneObject *object;

};

#endif // BASEPARSER_H
