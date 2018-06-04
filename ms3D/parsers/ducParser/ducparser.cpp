#include "ducparser.h"

ducParser::ducParser()
{
    str=NULL;
    isOk=false;
    file=new QFile;
    version=0;
}
////////////////////////////////////////
ducParser::~ducParser()
{
    file->close();
    delete file;
    delete str;
}
/////////////////////////////////////////////////////
void ducParser::writeInt(QString varName, int type, int value, int rangeMin, int rangeMax, QString description){
    if(str!=NULL){
        *str<<varName;
        *str<<type;
        *str<<value;
        *str<<rangeMin;
        *str<<rangeMax;
        *str<<description;
    }
}
////////////////////////////////////////////////////////////////////////////////////
void ducParser::writeFloat(QString varName, int type, float value, float rangeMin, float rangeMax, QString description){
    if(str!=NULL){
        *str<<varName;
        *str<<type;
        *str<<value;
        *str<<rangeMin;
        *str<<rangeMax;
        *str<<description;
    }
}
////////////////////////////////////////////////////////////////////////////////////
void ducParser::writeRawData(configItem *item){
    item->serialise(str);
}
////////////////////////////////////////////////////////////////////////////////////
void ducParser::writeString(QString varName, int type, QString value, int rangeMin, int rangeMax, QString description){
    if(str!=NULL){
        *str<<varName;
        *str<<type;
        *str<<value;
        *str<<rangeMin;
        *str<<rangeMax;
        *str<<description;
    }
}
////////////////////////////////////////////////////////////////////////////////////
bool ducParser::readVar(int *var, QString *varName, configItem *item){

    if(item==NULL){//если указателя на структуру нам не дали, то создаем свой с блекджеком и шлюхами
        configItem intItem;
        item=&intItem;
    }
    if(readRawData(item)){//читаем элемент
        if(varName!=NULL){//если дан указатель на имя переменной
            varName=&item->varName;//то пишем
        }
        *var=item->value.toInt();//преобразуем переменную
        return true;//все ок
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////////
bool ducParser::readVar(float *var, QString *varName, configItem *item){

    if(item==NULL){//если указателя на структуру нам не дали, то создаем свой с блекджеком и шлюхами
        configItem intItem;
        item=&intItem;
    }
    if(readRawData(item)){//читаем элемент
        if(varName!=NULL){//если дан указатель на имя переменной
            varName=&item->varName;//то пишем
        }
        *var=item->value.toFloat();//преобразуем переменную
        return true;//все ок
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////////
bool ducParser::readVar(QString *var, QString *varName, configItem *item){
    if(item==NULL){//если указателя на структуру нам не дали, то создаем свой с блекджеком и шлюхами
        configItem intItem;
        item=&intItem;
    }
    if(readRawData(item)){//читаем элемент
        if(varName!=NULL){//если дан указатель на имя переменной
            varName=&item->varName;//то пишем
        }
        var->fromUtf8(item->value);//преобразуем переменную
        return true;//все ок
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////////
bool ducParser::newFile(QString fileName){

    isOk=false;

    if(file->isOpen()){
        file->close();
    }
    if(str!=NULL){
        delete str;
        str=NULL;
    }

    bool l;
    file->setFileName(fileName);
    if(file->exists()){
        file->close();
        l=file->remove();
    }

    if(!file->open(QIODevice::ReadWrite)){
        QMessageBox box;
        box.setWindowTitle(tr("Ducparser error"));
        box.setText(tr("File ")+fileName+tr(" not open!"));
        box.setIcon(QMessageBox::Warning);
        box.exec();
        return false;
    }

    str=new QDataStream(file);
    QString t="duc";
    *str<<t;
    *str<<version;

    isOk=true;
    return true;
}
////////////////////////////////////////////////////////////////////
void ducParser::addNewItem(configItem *item){
    //itemsArray.append(item);
}
/////////////////////////////////////////////////////////////////////////////
void ducParser::saveConfigItemaArray(){
//    if(itemsArray.size()!=0){
//        if(str!=0){
//            for(int n=0;n!=itemsArray.size();n++){
//                itemsArray.at(n)->serialise(str);
//            }
//        }
//    }
}
/////////////////////////////////////////////////////////////////////////////
bool ducParser::loadFile(QString fileName){
    isOk=false;

    if(file->isOpen()){
        file->close();
    }
    if(str!=NULL){
        delete str;
        str=NULL;
    }

    file->setFileName(fileName);
    if(!file->open(QIODevice::ReadWrite)){
        QMessageBox box;
        box.setWindowTitle(tr("Ducparser error"));
        box.setText(tr("File ")+fileName+tr(" not open!"));
        box.setIcon(QMessageBox::Warning);
        box.exec();
        return false;
    }

    str=new QDataStream(file);
    QString t;
    *str>>t;
    if(t=="duc"){
        int v;
        *str>>v;
        if(v<=version){
            isOk=true;
            return true;
        }
    }

    return false;
}
///////////////////////////////////////////////////////////////////
void ducParser::closeFile(){
    file->close();
    delete str;
    str=NULL;
}
///////////////////////////////////////////////////////////////////
bool ducParser::readRawData(configItem *item){
    if(str!=NULL){
        if(!str->atEnd()){
            *str>>item->varName;
            *str>>item->type;
            *str>>item->value;
            *str>>item->rangeMinim;
            *str>>item->rangeMaxim;
            *str>>item->description;
            if(item->isValid()){
                return true;
            }
        }
    }
    return false;
}
///////////////////////////////////////////////////////////////////
bool ducParser::atEnd(){
    bool r=str->atEnd();
    return r;
}
///////////////////////////////////////////////////////////////////
