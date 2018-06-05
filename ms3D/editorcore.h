#ifndef EDITORCORE_H
#define EDITORCORE_H


#include <QOpenGLWidget>
#include <QFile>
#include <QFileInfo>
#include <QObject>
#include "enginecore.h"
#include "parsers/parserobj.h"




class editorCore : public QObject
{
    Q_OBJECT

public:
    editorCore();
    void setViewWidget(QOpenGLWidget *widget);
    bool loadMesh(QString fileName);
    QString getLastError();

protected:
    engineCore engine;
    QOpenGLWidget *viewWindow;
    QString lastError;



};

#endif // EDITORCORE_H
