#include "parserobj.h"

parserOBJ::parserOBJ()
{
    object=NULL;
}
///////////////////////////////////////////////////
parserOBJ::~parserOBJ()
{
    deleteObject();
}
///////////////////////////////////////////////////
bool parserOBJ::readFile(QString fileName){
    QFile *file=new QFile(fileName);
    bool rez=false;//результат парсинга

    if(!file->open(QIODevice::ReadOnly|QIODevice::Text)){
        return rez;//если не открылся выходим с ошибкой
    }
    if(parsObj(file)){//если прочиталось
        rez=true;
    }
    file->close();//закрываем файл
    delete file;
    return rez;
}
//////////////////////////////////////////////////////////
bool parserOBJ::parsObj(QFile *file){

    QVector<float>vertexArray;
    QVector<float>normalsArray;



    QVector<float>facesArray;//временный массив поверхностей. формат: поверхн/текстура/нормаль

    deleteObject();
    object=new sceneObject;

    QString tmp=file->readLine();
    while(!file->atEnd()){//читаем до конца файла
        if(tmp.left(1)=="o"){
            tmp=file->readLine();
            while(tmp.left(2)=="v "){//читаем пока не кончатся вершины
                if(!readNumbers(&tmp,&vertexArray)){//читаем вершины
                    return false;
                }
                tmp=file->readLine();//читаем следующую строку
            }
            while(tmp.left(2)=="vn"){//читаем нормали
                if(!readNumbers(&tmp,&normalsArray)){
                    return false;
                }
                tmp=file->readLine();//читаем следующую строку
            }
        }
        if(tmp.left(6)=="usemtl"){//читаем материал
           //ищем материал с таким-же именем
           int mCount=object->getMaterialsSize();
           int n;
           QString name=tmp.mid(7,-2);
           material *tmpMaterial;
           for(n=0;n!=mCount;n++){
               tmpMaterial=object->getMaterial(n);
               if(tmpMaterial->getName()==name){//если нашли имя,
                   break;//то пишем в этот-же материал
               }
           }
           if(n==mCount){//если не нашли
               tmpMaterial=new material;//то создаем новый
               tmpMaterial->setName(name);
           }

           tmp=file->readLine();
           if(tmp.left(1)=="s"){//пропускаем строку S
                tmp=file->readLine();
           }
           while(tmp.left(1)=="f"){//читаем поверхности
               if(!readNumbers(&tmp,&facesArray)){
                   return false;
               }
               tmp=file->readLine();
           }
           int size=facesArray.size()/3;
           int *tmpVIndices;
           int *tmpNIndices;
           //создаем массивы индексов
           int faces=tmpMaterial->getFacesCount();
           tmpVIndices=new int[size+faces];//вершины
           tmpNIndices=new int[size+faces];//нормали
           //заполняем массивы
           if(n==mCount){//если это новый материал
               for(int n=0;n!=size;n++){
                   tmpVIndices[n]=facesArray.at(n*3)-1;
                   tmpNIndices[n]=facesArray.at(n*3+2)-1;
               }
               //передаем указатели материалу
               tmpMaterial->setFacesCount(size+faces);
               tmpMaterial->setNormalsIndicesArray(tmpNIndices);
               tmpMaterial->setVertexIndicesArray(tmpVIndices);
               object->addMaterial(tmpMaterial);
           }
           else{//если материал существующий
               //здесь tmpMaterial указывает на object->material
               int nn;
               for(nn=0;nn!=faces;nn++){//сначала переносим существующие данные в новые массивы
                   tmpVIndices[nn]=tmpMaterial->getVertexIndicesArrayPointer()[nn];
                   tmpNIndices[nn]=tmpMaterial->getNormalsIndicesArrayPointer()[nn];
               }
               for(int n=0;n!=size;n++){//затем добавляем новые данные
                   tmpVIndices[nn+n]=facesArray.at(n*3)-1;
                   tmpNIndices[nn+n]=facesArray.at(n*3+2)-1;
               }
               //передаем указатели материалу
               tmpMaterial->setFacesCount(size+faces);
               tmpMaterial->setNormalsIndicesArray(tmpNIndices);
               tmpMaterial->setVertexIndicesArray(tmpVIndices);
           }
           facesArray.clear();//очищаем массив поверхностей т.к. у одного объекта их может быть много
        }
        else{
            tmp=file->readLine();
        }
    }
    //создаем массивы вершин и нормалей
    int size=vertexArray.size();//вершины
    float *v=new float[size];
    for(int n=0;n!=size;n++){
        v[n]=vertexArray.at(n);
    }
    object->setVertexArray(v,size);

    size=normalsArray.size();//нормали
    float *norm=new float[size];
    for(int n=0;n!=size;n++){
        norm[n]=normalsArray.at(n);
    }
    object->setNormalsArray(norm,size);

    return true;
}
///////////////////////////////////////////////////////////////////////////////////
bool parserOBJ::readNumbers(QString *string, QVector<float> *outVector){

    QString tmp;
    int end=0;
    int beg=0;
    float num=0;
    bool ok=true;
    bool endString=false;

    beg=string->indexOf(" ");//находим первый пробел-это будет начало числа
    while(!endString){//выполняем, пока не кончатся пробелы
        end=string->indexOf(" ",beg+1);//ищем следующий пробел - это будет конец числа
        if(end==-1){//если пробелов больше нет, то ищем коней строки
            end=string->indexOf("\n",beg+1);
            if(end==-1){//если и конца строки не найдено то ошибка
                return false;
            }
            endString=true;//и создаем условие выхода из цикла
        }
        tmp=string->mid(beg,end-beg);//получаем кусок строки между пробелами

        if(string->contains("/")){//если в строке имеются слеши
            int b=0,e=0;
            tmp.append("/");//добавляем в конец слеш, что-бы не морочиться
            tmp.remove(0,1);//удаляем первый пробел
            e=tmp.indexOf("/",b);
            while(e!=-1){
                QString t=tmp.mid(b,e-b);
                if(t.isEmpty()){
                    num=-1;//то в массив заносим -1
                    outVector->append(num);
                }
                else{
                    num=t.toDouble(&ok);
                    if(!ok){//если не оцифровывается
                        return false;//то ошибка
                    }
                    else{
                        outVector->append(num);//иначе пихаем в массив
                    }
                }

                b=e+1;
                e=tmp.indexOf("/",e+1);//ищем следующий слеш
            }
        }
        else{
            num=tmp.toFloat(&ok);//пробуем преобразовать в число
            if(!ok){
                return false;//если не выходит - то ошибка
            }
            else{
                outVector->append(num);//иначе пихаем в массив
            }
        }
        beg=end;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////
//bool parserOBJ::readNumSring(QString *string, unsigned char n,QVector<QString> *outVector){
//    /*
//  Читаем из строки string числа в буфер outVector
//  n-максимальное ожидаемое количество чисел
//  */
//    QString str;
//    int spacePos=0,spacePos1=0;

//    outVector->clear();

//    if(string->contains("/")){//если в строке имеются слеши

//    }

//    int nums=string->count(" ")+string->count("/")+1;//получаем количество чисел в строек. числа могут разделяться пробелами и слешами


//    if(nums>n){//если количество чисел больше ожидаемого то строка некошерная
//        return false;//выходим с ошибкой
//    }

//    for(int t=0;t!=nums;t++){
//         int sl=0,sp=0;// кол-ва знаков до следующего пробела и слеша
//            sp=string->indexOf(" ",spacePos+1);//считаем кол-во знаков до пробела

//            sl=string->indexOf("/",spacePos+1);//считаем кол-во знаков до слеша

//            //spacePos=string->indexOf(" ",spacePos+1);//считаем кол-во знаков до пробела
//            if((sp==-1) & (sl==-1)){//если пробел и слеш не найдены
//                //проверяем номер прохода
//                if(t==nums-1){//если последний то
//                    spacePos=string->indexOf("\n",spacePos+1);//считаем кол-во знаков до конца строки
//                }
//                else{//если не последний то строка некошерная
//                    return 1;//и выходим с ошибкой
//                }
//            }
//            else{
//                if((sp==-1)|(sl==-1)){//есля хоть одно значение <0
//                    if(sp>sl)spacePos=sp;//выбираем наибольшее кол-во знаков
//                    else spacePos=sl;
//                }
//                else{//иначе
//                    if(sp<sl)spacePos=sp;//выбираем наименьшее кол-во знаков
//                    else spacePos=sl;
//                }
//            }

//            str=string->mid(spacePos1,spacePos-spacePos1);
//            if(str!="/"){//если прочитанный символ не слеш
//                spacePos1=spacePos;//то двигаемся дальше
//                 outVector->append(str);//и записываем число
//            }
//            else{
//               // t=t-1;//иначе данный проход не считается и позиция не меняется
//                spacePos1=spacePos+1;
//                outVector->append("void");//и записываем пустоту
//            }
//    }
//    return 0;
//}
/////////////////////////////////////////////////////////////////////////////////////////////
sceneObject* parserOBJ::getSceneObject(){
    //указатель на объект можно запросить только раз
    //кто запросил объект, тот и отвечает за его удаление
    sceneObject *tmp=object;
    object=NULL;//если указатель запрошен, то парсер его забывает
    return tmp;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void parserOBJ::getAllMaterials(QVector<material *> *matArray){
//    for(int n=0;n!=objectsArray.size();n++){
//        for(int m=0;m!=objectsArray.at(n)->getMaterialsSize();m++){
//            matArray->append(objectsArray.at(n)->getMaterial(m));
//        }
//    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
void parserOBJ::deleteObject(){
    //пока указатель на объект не запрошен за него отвечает парсер
    if(object!=NULL){
        delete object;
    }
}
