//============================================================================
// Name        : Lab3-Ex1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "arrayQueue.h"


using namespace std;
int main(){
    arrayQueue<int> a;
    a.enqueue(8);
    a.enqueue(3);
    //a.dequeue();
    a.enqueue(2);
    a.enqueue(5);
    //a.dequeue();
    //a.dequeue();
    a.enqueue(9);
    a.enqueue(1);// from the example in class the queue should have 5,9,1
    try {
        cout<<"size is: "<<a.size()<<endl;
        cout<<"Remove from the queue: "<< a.dequeue()<<endl;
        cout<<"size is: "<<a.size()<<endl;
        cout<<"Remove the queue: "<<a.dequeue()<<endl;
        cout<<"size is: "<<a.size()<<endl;
        cout<<"Remove from the queue: "<<a.dequeue()<<endl;
        cout<<"size is: "<<a.size()<<endl;
        cout<<"Remove from the queue: "<<a.dequeue()<<endl;
        cout<<"size is: "<<a.size()<<endl;
        cout<<"Remove from the queue: "<<a.dequeue()<<endl;
        } catch(const char * message){
            cerr << "Error: " << message << endl;
        }



        return 0;
}

