/*
 * clockType.h
 *
 *  Created on: Feb 2, 2019
 *      Author: Phat Le
 */

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

#include <iostream>
using namespace std;

template<class T>
class arrayQueue
{
public:
        arrayQueue();
        void enqueue(T new_element);
        bool isEmpty();
        bool isFull();
        T dequeue();
        T front();
        int size();


private:
        int maxSize;
        T *queue;
        int length;
        int f;
        int r;
};

template<class T>
arrayQueue<T>::arrayQueue(){
        queue = new T[10];
        maxSize = 1;
        length = 0;
        f = 0;//index of the front element
        r =0;//index immediately past the rear element
}
////////////////////////////////////////////////////
//enqueue & dequeue

template<class T>
void arrayQueue<T>::enqueue(T new_element){
        if (isFull()){// if the stack is full throw an exception
            maxSize=maxSize*2;
            T *temp = new T[maxSize];//create a temporary list
            for (int i=f;i<r;i++){
                temp[i]=queue[i];
            }
            delete[]queue;
            queue = temp;
            f = 0;
        }
        queue[r]= new_element;
        r=(r+1)%maxSize;
}

template<class T>
T arrayQueue<T>::dequeue(){
        if (isEmpty()){
            throw "EmptyQueueException";
        }else{
            T temp = queue[f];
            f = (f+1)%maxSize;
            return temp;//return the front value
        }
}



/////////////////////////////////////////////////////
//size & isEmpty & isFull
template<class T>
bool arrayQueue<T>::isEmpty(){
        return (f==r);//return true if the front = rear
}

template<class T>
bool arrayQueue<T>::isFull(){
        if (size()==maxSize-1){
            return true;
        }else{
            return false;
        }
}

template<class T>
int arrayQueue<T>::size(){
        int num = (maxSize-f+r)%maxSize;
        return num;
}

//////////////////////
template<class T>
T arrayQueue<T>::front(){
        if (isEmpty()){
            throw "EmptyQueueException";
        }else{
           return queue[f];//return the value
        }
}
#endif /* ARRAYQUEUE_H_ */
