/*
 * clockType.h
 *
 *  Created on: Feb 2, 2019
 *      Author: Phat Le
 */

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include <iostream>
using namespace std;

template<class T>
class arrayStack
{
public:
        arrayStack();
        void push(T new_element);
        bool empty();
        T pop();
        T top();
        T size();


private:
        int maxSize;
        T *stack;
        int length;
};

template<class T>
arrayStack<T>::arrayStack(){
        stack = new T[100];
        maxSize = 100;
        length = 0;
}
////////////////////////////////////////////////////
//push & pop

template<class T>
void arrayStack<T>::push(T new_element){
        if (length == maxSize){// if the stack is full throw an exception
            throw "FullStackException";
        }else{
            stack[length]= new_element;
            length++;
        }
}

template<class T>
T arrayStack<T>::pop(){
        if (empty()){
            throw "EmptyStackException";
        }else{
            length--;
            return stack[length];//return the value
        }
}



/////////////////////////////////////////////////////
//size & empty
template<class T>
bool arrayStack<T>::empty(){
        return size()==0;//return true if the size equal to 0
}

template<class T>
T arrayStack<T>::size(){
        return length;
}

//////////////////////
template<class T>
T arrayStack<T>::top(){
        if (empty()){
            throw "EmptyStackException";
        }else{
           return stack[length-1];//return the value
        }
}
#endif /* ARRAYSTACK_H_ */
