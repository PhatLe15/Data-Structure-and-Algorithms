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

using namespace std;
int main(){
    arrayList<int> a,b;//create 2 objects
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
    //operator=
    cout<<"copy operator a to b"<<"//////////////////////////"<<endl;
    b=a;
    cout<<"The smallest member is: "<<b.getMin(4)<<endl;
    b.print();
    cout<<"////////////////////////////////"<<endl;
    //clearList
    cout<<"clear the list"<<endl;
    a.clearList();
    a.print();

    return 0;
}

