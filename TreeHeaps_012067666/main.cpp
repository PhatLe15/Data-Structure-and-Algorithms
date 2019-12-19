//============================================================================
// Name        : Lab10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "maxheap.h"
#include "treeheap.h"
using namespace std;

int main() {
    maxheap<int> a;
    a.insert(4);
    a.insert(5);
    a.insert(7);
    a.insert(9);
    a.insert(55);
    a.insert(97);
    a.insert(100);
    a.insert(3);
    a.print();
    cout<<"After the sort list function: "<<endl;
    a.sort();
    a.print();

	return 0;
}
