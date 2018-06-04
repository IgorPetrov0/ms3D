#include "configitem.h"

configItem::configItem(int value, int rangeMin, int rangeMax, QString description)
{
    this->value.setNum(value);
    rangeMinim.setNum(rangeMin);
    rangeMaxim.setNum(rangeMax);
    this->description=description;
    type=DUC_INT;
}
///////////////////////////////////////////////////////////////
configItem::configItem(){

}
///////////////////////////////////////////////
configItem::~configItem()
{

}
///////////////////////////////////////////////
bool configItem::isValid(){
    bool ok=false;

    switch(type){
        case 0:{
            float v=value.toFloat(&ok);
            if(ok){
                float rmax=rangeMaxim.toFloat(&ok);
                if(ok){
                    float rmin=rangeMinim.toFloat(&ok);
                    if(ok){
                        if(rmin==rmax){
                            return true;
                        }
                        if((v>=rmin)&(v<=rmax)){
                            return true;
                        }
                    }
                }
            }
            break;
        }
        case 1:{
            int v=value.toInt(&ok);
            if(ok){
                int rmax=rangeMaxim.toInt(&ok);
                if(ok){
                    int rmin=rangeMinim.toInt(&ok);
                    if(ok){
                        if(rmin==rmax){
                            return true;
                        }
                        if((v>=rmin)&(v<=rmax)){
                            return true;
                        }
                    }
                }
            }
            break;
        }
        case 2:{
            int rmin=rangeMaxim.toInt(&ok);
            if(ok){
                int rmax=rangeMaxim.toInt(&ok);
                if(rmin==rmax){
                    return true;
                }
                if((value.size()>=rmin)&(value.size()<=rmax)){
                    return true;
                }
            }
            break;
        }
    }
    return false;
}
/////////////////////////////////////////////////////////////////////
void configItem::serialise(QDataStream *str){
    *str<<varName;
    *str<<type;
    *str<<value;
    *str<<rangeMinim;
    *str<<rangeMaxim;
    *str<<description;
}
/////////////////////////////////////////////////////////////////////





