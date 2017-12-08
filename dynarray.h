#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream> //String stream
#include <stdexcept>
#include <exception>

#define defaultCapacity 2

using namespace std;

template<typename passedType>
class DynArray
{
   public:
      DynArray(int myCapacity = defaultCapacity);
      ~DynArray();
      int size() const;
      int capacity();
      void clear();
      void push_back(passedType n);
      passedType pop_back();
      passedType& at(int x);
      passedType& at(int x) const;
      
      passedType& back();  //New functions for project 13.4
      passedType& front();
      DynArray(const DynArray&);
      DynArray& operator=(const DynArray&);
      passedType& operator[](int n);
      
   private:
      int dSize;
      int dCapacity;
      passedType* data;
};

template<typename passedType>
DynArray<passedType>::DynArray(int myCapacity)
{
   this->dSize = 0;
   this->dCapacity = myCapacity;
   this->data = new passedType[myCapacity];
}

template<typename passedType>
DynArray<passedType>::~DynArray()
{
   delete this->data;
}

template<typename passedType>
int DynArray<passedType>::size() const
{
   return this->dSize;
}

template<typename passedType>
int DynArray<passedType>::capacity()
{
   return this->dCapacity;
}

template<typename passedType>
void DynArray<passedType>::clear()
{
   delete this->data;
   this->dSize = 0;
   this->data = new passedType[defaultCapacity];
   this->dCapacity = defaultCapacity;
}

template<typename passedType>
void DynArray<passedType>::push_back(passedType passedVal)
{
   if(this->dSize == this->dCapacity)
   {
      int i;
      this->dCapacity *= 2;
      passedType* tempPointer = new passedType[this->dCapacity];
      for(i = 0; i < this->dSize; i++)
      {
         tempPointer[i] = this->data[i];
      }
      delete this->data;
      this->data = tempPointer;
      //delete tempPointer;                     FIXME GET RID OF TEMPPOINTER
   }
   this->data[this->dSize] = passedVal;
   this->dSize++;
}

template<typename passedType>
passedType DynArray<passedType>::pop_back()
{
   this->dSize--;
   return this->data[this->dSize];
}

template<typename passedType>
passedType& DynArray<passedType>::at(int passedVal)
{
   if(passedVal < 0 || passedVal >= this->dSize)
   {
      throw runtime_error("invalid index");
   } else {
      return this->data[passedVal];
   }
}

template<typename passedType>
passedType& DynArray<passedType>::at(int passedVal) const
{
   if(passedVal < 0 || passedVal >= this->dSize)
   {
      throw runtime_error("invalid index");
   } else {
      return this->data[passedVal];
   }
}

template<typename passedType>
passedType& DynArray<passedType>::back()
{
    if(this->dCapacity == 0 || this->dSize == 0)
    {
        throw runtime_error("Empty vector");
    }
    return this->data[(this->dSize -1)];    //FIX ME RETURN RIGHT VALUE
}

template<typename passedType>
passedType& DynArray<passedType>::front()
{
    if(this->dCapacity == 0 || this->dSize == 0)
    {
        throw runtime_error("Empty vector");
    }
    return this->data[0];                   //FIX ME RETURN RIGHT VALUE
}

template<typename passedType>
DynArray<passedType>::DynArray(const DynArray& passedArray)
{
    DynArray* newArray = new DynArray();
    //newArray->clear();
    int tempSize = passedArray.size();
    for(int i = 0; i < tempSize; i++)
    {
        newArray->push_back(passedArray.at(i));
    }
}

template<typename passedType>
DynArray<passedType>& DynArray<passedType>::operator=(const DynArray& passedArray)
{
    DynArray* newArray = new DynArray();
    //newArray.clear();
    int tempSize = passedArray.size();
    for(int i = 0; i < tempSize; i++)
    {
        newArray->push_back(passedArray.at(i));
    }
}

template<typename passedType>
passedType& DynArray<passedType>::operator[](int n)
{
    return this->at(n);
}