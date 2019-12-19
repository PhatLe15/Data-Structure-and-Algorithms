//============================================================================
// Name        : Lab3-Ex1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "arrayStack.h"
#include "myInfixPostfix.h"
#include "stlInfixPostfix.h"


using namespace std;
int main(){

    //Excercise 1:
    cout<<"Excercise 1: "<<endl;
    arrayStack<int> a;
    //a.pop();
    a.push(5);
    a.push(6);
    //a.pop();
    try {
        cout<<"size is: "<<a.size()<<endl;
            cout<<"Pop the stack: "<< a.pop()<<endl;
            cout<<"size is: "<<a.size()<<endl;
            cout<<"Pop the stack: "<<a.pop()<<endl;
            cout<<"size is: "<<a.size()<<endl;
            //cout<<"Pop the stack: "<<a.pop(); delete the comment if the grader want to check if its empty
        } catch(const char * message){
            cerr << "Error: " << message << endl;
        }



    cout<<"/////////////////////////////////////"<<endl;
    cout<<"Excercise 2: "<<endl;
    string g="A+B-C";
    string b="(A+B)*C";
    string c="(A+B)*(C-D)";
    string d = "A+((B+C)*(E-F)-G)/(H-I)";
    string e = "A+B*(C+D)-E/F*G+H";
    try {
        string f = inFixtoPostFix(e);
        cout<<f<<endl;
    } catch(const char * message){
        cerr << "Error: " << message << endl;
    }

    cout<<"/////////////////////////////////////////"<<endl;
    cout<<"Excercise 3: "<<endl;

    try {
            string h = stlInFixtoPostFix(g);
            cout<<h;
        } catch(const char * message){
            cerr << "Error: " << message << endl;
        }
    return 0;
}

