#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include "defines.h"

//шаблон класса массива. нужен для удобства использования массивов с указанием их размеров

using namespace std;
template<class pointerType> class msArray
{
public:
    msArray();
    msArray(arraySize pSize);
    msArray(msArray<pointerType> *arr);//конструктор копирования
    msArray(pointerType* msArray, arraySize size);
    ~msArray();
    void setArray(arraySize pSize);
    pointerType &operator [](arraySize t);
    pointerType &operator =(pointerType& arr);
    bool operator ==(msArray<pointerType> &arr);
    bool operator !=(msArray<pointerType> &arr);
    void fillArray(vector<pointerType> *arr);//заполнение массива из вектора
    void deletePointers();//последовательно удаляет все объекты, если элементы массива являются указателями
    void addElement(arraySize index, pointerType element);//добавляет элемент в массив на указанную позицию
    pointerType const *getArrayPointer();//возвращает указатель на массив
    arraySize getSize();//возвращает размер массива
    void clear();

protected:
    pointerType *arrayPointer;
    arraySize size;



};
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
/// описание и реализация ДОЛЖНЫ БЫТЬ В ОДНОМ ФАЙЛЕ!!!!!!!!!!!!!!!!!!!!!!!!!!

template <class pointerType>
msArray<pointerType>::msArray(arraySize pSize)
{
    setArray(pSize);
}
////////////////////////////////////////////////////////////
template<class pointerType>
msArray<pointerType>::msArray(){
    arrayPointer=NULL;
    size=0;
}
///////////////////////////////////////////////////////////
template<class pointerType>
msArray<pointerType>::msArray(msArray<pointerType> *arr){
    setArray(arr->getSize());
    for(unsigned int n=0;n!=size;n++){
        arrayPointer[n]=(*arr)[n];
    }
}
//////////////////////////////////////////////////////////
template<class pointerType>
msArray<pointerType>::msArray(pointerType *arr, arraySize size){
    arrayPointer=arr;
    this->size=size;
}
//////////////////////////////////////////////////////////
template<typename pointerType>
msArray<pointerType>::~msArray(){
   clear();
}
///////////////////////////////////////////////////////////
template <class pointerType>
void msArray<pointerType>::setArray(arraySize pSize){
    arrayPointer=new pointerType[pSize];
    size=pSize;
}
///////////////////////////////////////////////////////////
template<typename pointerType>
pointerType &msArray<pointerType>::operator [](arraySize t){
    return arrayPointer[t];
}
//////////////////////////////////////////////////////////////
template<class pointerType>
void msArray<pointerType>::fillArray(vector<pointerType> *arr){
    for(unsigned int n=0;n!=size;n++){//заполняем только выделенные элементы массива
        arrayPointer[n]=arr->at(n);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
void msArray<pointerType>::deletePointers(){
    for(unsigned int n=0;n!=size;n++){
        delete arrayPointer[n];
    }
    clear();
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
void msArray<pointerType>::addElement(arraySize index, pointerType element){
    arrayPointer[index]=element;
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
pointerType const *msArray<pointerType>::getArrayPointer(){
    return arrayPointer;
}
////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
arraySize msArray<pointerType>::getSize(){
    return size;
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
void msArray<pointerType>::clear(){
    delete []arrayPointer;
    arrayPointer=NULL;
    size=0;
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
pointerType& msArray<pointerType>::operator =(pointerType &arr){
    clear();
    size=arr.getSize();
    arrayPointer=new pointerType[size];
    for(unsigned int n=0;n!=size;n++){
        arrayPointer[n]=arr[n];
    }
    return *this;
}
//////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
bool msArray<pointerType>::operator ==(msArray<pointerType> &arr){
    if(arr.getSize()!=size){
        return false;
    }
    for(unsigned int n=0;n!=size;n++){
        if(this->operator [](n)!=arr[n]){
            return false;
        }
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
bool msArray<pointerType>::operator !=(msArray<pointerType> &arr){
    return !operator ==(arr);
}
///////////////////////////////////////////////////////////////////////////////////////////




#endif // ARRAY_H
