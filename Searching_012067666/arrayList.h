/*
 * clockType.h
 *
 *  Created on: Feb 2, 2019
 *      Author: Phat Le
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
using namespace std;



template<class elemType>
class arrayList
{
public:
      arrayList();
      ~arrayList();
      bool isEmpty()const;
      bool isFull()const;
      int listSize()const;
      int maxListSize()const;
      void print();
      bool isItemAtEqual(int location,elemType new_member);
      void insertAt(int location,elemType new_member);
      void insertEnd(elemType new_member);
      void removeAt(int location);
      elemType retrieveAt(int location);
      void replaceAt(int location, elemType new_member);
      void clearList();
      void operator =(const arrayList &a);
      elemType getMin(unsigned int n=0);
      unsigned int seqSearchIter (elemType element);
      unsigned int seqSearchRec (int size, elemType element);

private:
      int length;
      int maxSize;
      elemType *list;

};

template<class elemType>
unsigned int arrayList<elemType>::seqSearchIter(elemType element){
        for (int i= 0; i<= length-1; i++){
            if (list[i]==element){
                return i;
            }
        }
        return -1;
}

template<class elemType>
unsigned int arrayList<elemType>::seqSearchRec(int size, elemType element){
        if (size<1){
            return -1;
        }if (list[size]==element){
            return size;
        }
        return seqSearchRec(size-1, element);
}

template<class elemType>
elemType arrayList<elemType>::getMin(unsigned int n){
        if(n==1){
            return list[0];
        }
        return min(list[n-1],getMin(n-1));
}
//constructor
template<class elemType>
arrayList<elemType>::arrayList(){
        list = new elemType[10];
        length = 0;
        maxSize = 10;//I want my max size to be 10
}
//Destructor
template<class elemType>
arrayList<elemType>::~arrayList(){
        delete []list;
}

//check if list is empty
template<class elemType>
bool arrayList<elemType>::isEmpty()const{
        return (length==0);  //if the length is 0
}


template<class elemType>
bool arrayList<elemType>::isFull()const{
        return (length == maxSize);
}

template<class elemType>
int arrayList<elemType>::listSize()const{
        return length;
}

template<class elemType>
int arrayList<elemType>::maxListSize()const{
        return maxSize;//return maximum possible size of the list
}

template<class elemType>
void arrayList<elemType>::print(){
        if(length==0){
            list[0]=0;
        }else{
            for(int i=0;i<length-1;i++){
                cout<<list[i]<<",";
            }
        }

        cout<<list[length]<<endl;
}

template<class elemType>
bool arrayList<elemType>::isItemAtEqual(int location,elemType new_member){
        return list[location]== new_member;
}

template<class elemType>
void arrayList<elemType>::insertAt(int location, elemType new_member){
        //if the new length is equal to the maxSize, increase the size of the list as well as increase the maxsize
        if (isFull()){
            maxSize=maxSize*2;
            //length++;
            elemType *temp = new elemType[maxSize];//create a temporary list
            for (int i=0;i<length;i++){
                temp[i]=list[i];
            }
            delete[]list;
            list = temp;
            //length++;
        }
        for (int i= length; i>location;i--){
            list[i]= list[i-1];//move every element to the left.
        }
        list[location]=new_member;
        length++;
}

template<class elemType>
void arrayList<elemType>::insertEnd(elemType new_member){
        if(isFull()){
            maxSize=length+10;
            elemType *temp = new elemType[length+1];//create a temporary list
            for (int i=0;i<length;i++){
                temp[i]=list[i];
            }
            delete[]list;
            list = temp;

        }
        length++;
        list[length]=new_member;
}

template<class elemType>
void arrayList<elemType>::removeAt(int location){
    for (int i= location; i<length;i++){
        list[i]= list[i+1];//move every element to the left.
    }
    length--;
}

template<class elemType>
elemType arrayList<elemType>::retrieveAt(int location){
        return list[location];
}

template<class elemType>
void arrayList<elemType>::replaceAt(int location,elemType new_member){
        list[location]=new_member;
}

template<class elemType>
void arrayList<elemType>::clearList(){
        length=0;
}//is clear list means 0?maybe I should use remove

template<class elemType>
void arrayList<elemType>::operator =(const arrayList &a){
        if (list== a.list){
            return;
        }else{
            for (int i=0; i<=a.length;i++){
                list[i]=a.list[i];
            }
        }
            length=a.length;
}

#endif /* ARRAYLIST_H_ */
