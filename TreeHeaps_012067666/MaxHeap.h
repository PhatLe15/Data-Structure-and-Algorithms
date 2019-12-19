/*
 * clockType.h
 *
 *  Created on: Feb 2, 2019
 *      Author: Phat Le
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include <iostream>
using namespace std;

template<class elemType>
class maxheap
{
public:
      maxheap();
      ~maxheap();
      void print();
      int insert(elemType);
      void buildheap();
      int search(elemType);
      void sort();

private:
      void heapify(int, int);
      int maxSize;
      int length;
      elemType *list;

};

//constructor
template<class elemType>
maxheap<elemType>::maxheap(){
        length =0;
        maxSize =100;//assume that the max size is 100
        list= new elemType[maxSize];
}

//Destructor
template<class elemType>
maxheap<elemType>::~maxheap(){
        delete []list;
}

template<class elemType>
void maxheap<elemType>::heapify(int low, int high){
        int max = low;// let the largest num be the root
        int left = 2*low+1;
        int right = 2*low+2;
        if(left <high && list[left]> list[max]){// check if the left side bigger than max
            max = left;
        }if(right <high && list[right]> list[max]){//check the right side
            max = right;
        }if(max!=low){
            elemType temp = list[low];
            list[low]=list[max];
            list[max]=temp;
            heapify(max, high);
        }
}

template<class elemType>
//hash function
void maxheap<elemType>::print(){
     cout<<"The list is: "<<endl;
     for (int i =0; i<length-1;i++){
         cout<<list[i]<<",";
     }
     cout<<list[length-1];
     cout<<endl;

}

//buildheap
template<class elemType>
void maxheap<elemType>::buildheap(){
        for(int i=length/2-1;i>=0;i--){
            heapify(i,length-1);
        }
}
//insert
template<class elemType>
int maxheap<elemType>::insert(elemType a){
        list[length]=a;
        length++;
        buildheap();
        return search(a);
}

template<class elemType>
int maxheap<elemType>::search(elemType a){
        for (int i=0; i<length;i++){
            if(list[i]==a){
                return i;
            }
        }
        return -1;
}

template<class elemType>
void maxheap<elemType>::sort(){
        elemType temp;
        buildheap();
        for(int i=length-1;i>=0; i--){
            temp = list[i];//swap the list then heapify it
            list[i]= list[0];
            list[0]=temp;
            heapify(0,i);
        }
}
#endif /* MAXHEAP_H_ */
