#include <iostream>

using namespace std;

bool palindrome (const string &s){
    int length = s.length();
    if (length <=1){
        return true;
    }
    if (s.at(0)==s.at(length-1)){
        return palindrome(s.substr(1,(length-2)));
    }else{
        return false;
    }
}

int main(){
	string a="racecar";
	if (palindrome(a)){
	    cout<<"It is a palindrome"<<endl;
	}else{
	    cout<<"It is not a palindrome"<<endl;
	}
	return 0;
}
