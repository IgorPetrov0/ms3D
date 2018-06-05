#include "editorcore.h"

editorCore::editorCore()
{

}
/////////////////////////////////////////////////////////////
void editorCore::setViewWidget(QOpenGLWidget *widget){
    viewWindow=widget;
}
/////////////////////////////////////////////////////////////
bool editorCore::loadMesh(QString fileName){
    QFile file(fileName);
    if(file.exists()){
        QFileInfo fi(file);
        if(fi.suffix()==".obj"){
            parserOBJ parser;
            if(parser.readFile(fileName)){
                return true;
            }
            lastError=parser.getLastError();
        }
        else{
            lastError=tr("Format ")+fi.suffix()+tr(" not supported.");
        }
    }
    else{
        lastError=tr("File ")+fileName+tr(" not exist.");
    }
    return false;
}
///////////////////////////////////////////////////////////////
QString editorCore::getLastError(){
    QString tmp=lastError;
    lastError.clear();
    return tmp;
}
