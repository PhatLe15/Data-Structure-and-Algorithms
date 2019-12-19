//============================================================================
// Name        : Lab10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "hashtable.h"
#include "hashtablechaining.h"
using namespace std;

int main() {
    //Hashtable with linear probing
    cout<<"Hashtable with linear probing :"<<endl<<endl;
    HashTable<string> a;
    a.insert("Hello");
    a.insert("a");
    a.insert("g");
    a.insert("c");
    a.insert("b");
    a.insert("f");
    a.print();

    cout<<endl<<"Check if Hello is already existed: "<<endl;
    if(a.insert("Hello")==false){
        cout<<"it's already existed"<<endl;
    }

    a.print();
    cout<<a.search("Hello")<<" is removed"<<endl;
    a.print();

    cout<<"/////////////////////////////////////////////////////////////////"<<endl<<endl;
    cout<<"Hash table with chaining: "<<endl<<endl;
    HashTableChaining<string> b;
    b.print();
    b.insert("hello");
    b.insert("hello");
    b.insert("there");
    b.insert("a");
    b.insert("b");
    b.insert("c");
    b.insert("d");
    b.insert("e");
    b.insert("f");
    b.insert("g");
    b.insert("h");
    b.insert("i");
    b.insert("j");
    b.insert("k");
    b.insert("f");
    b.insert("l");
    b.insert("m");
    b.insert("n");
    b.insert("o");
    b.insert("p");
    b.insert("q");
    b.insert("z");
    b.print();
    cout<<"The removed item is: "<<b.search("hello")<<endl;


    b.print();
	return 0;
}
