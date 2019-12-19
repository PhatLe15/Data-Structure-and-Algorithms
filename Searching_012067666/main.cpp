//============================================================================
// Name        : Lab3-Ex1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include "arrayList.h"
#include "sortedarrayList.h"
#include "linkedListList.h"

using namespace std;
int main(){
    cout<<"Excercise 1:"<<endl;
    arrayList<int> a;//create 2 objects
    //isEmpty test
    if (a.isEmpty()){
        cout<<"//////////////////////////"<<endl<<"a is empty"<<endl<<"//////////////////////////"<<endl;
    }

    for (int i=0;i<5;i++){//put elements from 0-4 to object a
        a.insertAt(0,i);
    }

    //isFull test
    if (a.isFull()){//after insert 5 elements to a
        cout<<"//////////////////////////"<<endl<<"a is Full"<<endl<<"//////////////////////////"<<endl;
    }
    //listSize
    cout<<"//////////////////////////"<<endl<<"The size of list a: "<<a.listSize()<<endl<<"//////////////////////////"<<endl;
    //maxListSize
    cout<<"The max list size of a: "<<a.maxListSize()<<endl<<"//////////////////////////"<<endl;
    //print the list member of a
    cout<<"a list: ";
    a.print();
    //check if the item at position matches the 2nd parameter
    if(a.isItemAtEqual(0,4)){
        cout<<"The item is 4 and it is the same as the item at location 0"<<endl;
    }

    //insert object at given location
    cout<<"//////////////////////////"<<endl<<"insert at location 0:"<<endl;
    a.insertAt(0,2);// put 2 at location 0
    //cout<<"The max list size of a: "<<a.listSize()<<endl;
    a.print();
    cout<<"///////////////////"<<endl;
    //insertEnd
    cout<<"Insert 5 to the end of the list"<<endl;
    a.insertEnd(5);//put 5 to the end of the list
    a.print();
    cout<<"//////////////////////////"<<endl;
    //removeAt()
    cout<<"remove the value at location 6"<<endl;
    a.removeAt(6);
    a.print();

    //retrieveAt();
    cout<<"//////////////////////////"<<endl<<"Retrieve element at location 1: "<<a.retrieveAt(1)<<endl;

    cout<<"//////////////////////////"<<endl;
    //replaceAt
    cout<<"replace the value at location 2 with 5"<<"//////////////////////////"<<endl;
    a.replaceAt(2,5);
    a.print();
    cout<<"//////////////////////////"<<endl;

    cout<<"////////////////////////////////"<<endl;
    cout<<"List A is: ";
    a.print();
    cout<<"////////////////////////////////"<<endl;
    cout<<"Iteration linear search: "<<endl;
    cout<<"Searching number 1 in array a..."<<endl;
    cout<<"The location of number 1 is: "<< a.seqSearchIter(1)<<endl;
    cout<<"////////////////////////////////"<<endl;
    cout<<"Recursion linear search: "<<endl;
    cout<<"Searching number 1 in array a... "<<endl;
    cout<<"The location of number 1 is: "<< a.seqSearchRec(a.listSize(),1);
///////////////////////////////////////////////////
    cout<<endl<<endl;
    //Exercise2:
    cout<<"Excercise 2:"<<endl<<endl;
    sortedarrayList<int> b;//create 2 objects
        //isEmpty test
        if (b.isEmpty()){
            cout<<"//////////////////////////"<<endl<<"a is empty"<<endl<<"//////////////////////////"<<endl;
        }

        /*for (int i=0;i<5;i++){//put elements from 0-4 to object a
            a.insert(i);
        }*/

        b.insert(3);
        b.insert(5);
        b.insert(4);
        b.insert(0);
        b.insert(7);
        b.insert(6);
        b.print();
        b.remove(5);
        b.print();
        cout<<b.binSearchRec(0,b.listSize(),4);

        ///////////////////////////////////////////////////
        cout<<endl<<endl;
        //Exercise3:
        cout<<"Excercise 3:"<<endl<<endl;
        linkedListList<int> c;
        c.insertAt(0,1);
        c.insertAt(0,2);
        c.insertAt(0,2);
        c.insertAt(0,5);
        c.print();
        if(c.seqSearchIter(5)){
            cout<<"Five is in the list"<<endl;
        }else{
            cout<<"Five is not in the list"<<endl;
        }

        if(c.seqSearchRec(c.node_accessor(),4)){
            cout<<"Four is in the list";
        }else{
            cout<<"Four is not in the list";
        }


    return 0;
}

