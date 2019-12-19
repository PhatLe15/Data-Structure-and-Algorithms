#include <iostream>
#include "arrayStack.h"
#include "myInfixPostfix.h"

using namespace std;

int prece(char c){//use integer to compare the precedence
    if (c=='*'|| c=='/'){
        return 2;
    }else if (c=='+'|| c=='-'){
        return 1;
    }else{
        return -1;
    }
}

string inFixtoPostFix(const string a){
    arrayStack<char> stack;
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

                postfix+=stack.pop();
            }
            if (stack.top()=='('){
                stack.pop();
            }

        }
        else if (a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
            while (((!stack.empty())&& stack.top()!='(') && prece(stack.top()) >= prece(a[i])){
                char op = stack.pop();
                postfix+=op;
            }
            stack.push(a[i]);
        }
    }
    while(!stack.empty()){
        postfix+= stack.pop();
    }
    return postfix;
}

