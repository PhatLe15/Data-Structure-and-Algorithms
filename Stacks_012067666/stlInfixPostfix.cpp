#include <iostream>
#include <stack>
#include "stlInfixPostfix.h"

using namespace std;

int stlprece(char c){//use integer to compare the precedence
    if (c=='*'|| c=='/'){
        return 2;
    }else if (c=='+'|| c=='-'){
        return 1;
    }else{
        return -1;
    }
}

string stlInFixtoPostFix(const string a){
    stack<char> stack;
    string postfix="";
    int length = a.length();
    for (int i = 0; i<length ;i++){
        if ((a[i] >= 'a' && a[i]<='z')||(a[i]>='A' && a[i] <='Z')){
           postfix+=a[i];
        }
        else if (a[i]=='('){
            stack.push(a[i]);
        }
        else if (a[i]==')'){
            while (!stack.empty() &&stack.top()!='('){
                //cout<<stack.size();
                postfix+=stack.top();// cannot use pop for the STL stack
                stack.pop();
            }
            if (stack.top()=='('){
                stack.pop();
            }

        }
        else if (a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
            //stack.push(a[i]);
            while (((!stack.empty())&& stack.top()!='(') && stlprece(stack.top()) >= stlprece(a[i])){

                char op = stack.top();
                stack.pop();
                postfix+=op;
            }
            stack.push(a[i]);
        }
    }
    while(!stack.empty()){
        postfix+= stack.top();
        stack.pop();
    }
    return postfix;
}

