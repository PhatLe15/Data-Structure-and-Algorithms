/*
 * clockType.h
 *
 *  Created on: Feb 2, 2019
 *      Author: Phat Le
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_

#include <iostream>
using namespace std;





template<class elemType>
class sortedarrayList
{
public:
      sortedarrayList();
      ~sortedarrayList();
      bool isEmpty()const;
      bool isFull()const;
      int listSize()const;
      int maxListSize()const;
      void print();
      //bool isItemAtEqual(int location,elemType new_member);
      void insert(elemType new_member);
      void remove(elemType a);
      void clearList();
      elemType getMax();
      unsigned int binSearchIter (elemType element);
      unsigned int binSearchRec (int first, int last, elemType element);
      //for the recursive search, I need a scope variable in order to manipulate the recursion process.

private:
      int length;
      int maxSize;
      elemType *list;

};

//binary search
template<class elemType>
unsigned int sortedarrayList<elemType>::binSearchIter(elemType element){
        int first = 0;
        int last = length-1;
        int mid;
        bool found =false;

        while (first <= last && !found){
            mid = (first+last)/2;

            if (list[mid]==element){
                found = true;
            }else if(list[mid]> element){
                last = mid-1;
            }else{
                first = mid+1;
            }
        }
        if(found){
            return mid;
        }else{
            return -1;
        }
}

template<class elemType>
unsigned int sortedarrayList<elemType>::binSearchRec(int first,int last , elemType element){
        if (first<= last){
            int mid = (first+last)/2;

            if (list[mid]==element){
                return mid;
            }else if(mid >element){
                return binSearchRec(first,mid-1,element);
            }else{
                return binSearchRec(mid+1, last, element);
            }

        }
        return -1;
}

template<class elemType>
elemType sortedarrayList<elemType>::getMax(){
      elemType max= list[0];
      for (int i=0; i<length;i++){
          if(list[i]>max){
              max=list[i];
          }
      }
      return max;
}
//constructor
template<class elemType>
sortedarrayList<elemType>::sortedarrayList(){
        list = new elemType[10];
        length = 0;
        maxSize = 10;//I want my max size to be 10
}
//Destructor
template<class elemType>
sortedarrayList<elemType>::~sortedarrayList(){
        delete []list;
}

//check if list is empty
template<class elemType>
bool sortedarrayList<elemType>::isEmpty()const{
        return (length==0);  //if the length is 0
}


template<class elemType>
bool sortedarrayList<elemType>::isFull()const{
        return (length == maxSize);
}

template<class elemType>
int sortedarrayList<elemType>::listSize()const{
        return length;
}

template<class elemType>
int sortedarrayList<elemType>::maxListSize()const{
        return maxSize;//return maximum possible size of the list
}

template<class elemType>
void sortedarrayList<elemType>::print(){
        if(length==0){
            list[0]=0;
        }else{
            for(int i=0;i<length-1;i++){
                cout<<list[i]<<",";
            }
        }

        cout<<list[length-1]<<endl;
}

template<class elemType>
void sortedarrayList<elemType>::insert(elemType new_member){
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
        if (isEmpty()){
            list[0]= new_member;
            length++;
        }else{
            int n=0;
            if (new_member>getMax()){
                list[length]=new_member;
                length++;
            }else{
                while (list[n]< new_member){
                    n++;//count until it is smaller than a member
                }
                length++;
                for (int i= length; i>n;i--){
                    list[i]= list[i-1];//move every element to the left.
                }

                list[n]= new_member;
            }
        }
}

template<class elemType>
void sortedarrayList<elemType>::remove(elemType a){
    for (int i= binSearchIter(a); i<length;i++){
        list[i]= list[i+1];//move every element to the left.
    }
    length--;
}

template<class elemType>
void sortedarrayList<elemType>::clearList(){
        length=0;
}//is clear list means 0?maybe I should use remove

#endif /* SORTEDARRAYLIST_H_ */
