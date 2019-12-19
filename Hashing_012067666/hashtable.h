/*
 * clockType.h
 *
 *  Created on: Feb 2, 2019
 *      Author: Phat Le
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
using namespace std;

template<class elemType>
class HashTable
{
public:
      HashTable();
      int hash(elemType);
      void print();
      bool insert(elemType);
      ~HashTable();
      elemType search(elemType);

private:
      int HTsize;
      int length;
      elemType *table;

};

//constructor
template<class elemType>
HashTable<elemType>::HashTable(){
        length =0;
        HTsize =5;
        table= new elemType[10];

        for (int i=0; i<HTsize;i++){
            table[i]= "empty" ;
        }
}

//Destructor
template<class elemType>
HashTable<elemType>::~HashTable(){
        delete []table;
}

template<class elemType>
//hash function
int HashTable<elemType>::hash(elemType key){
    int hash=0;
    int index;
    for (int i=0; i<key.length();i++){
        hash = hash + (int)key[i];
        //cout<<"hash = "<<hash<<endl;
    }

    index = hash % HTsize;
    //cout<<"index is"<<index<<endl;
    return index;
}

template<class elemType>
//hash function
void HashTable<elemType>::print(){
     cout<<"Hash table list is: "<<endl;
     for (int i =0; i<HTsize;i++){
         if(table[i]!= "empty"){
             cout<<table[i];
             cout<<endl;
         }
     }
     if (length == 0){
         cout<<"table is empty";
     }

}

//insert
template<class elemType>
bool HashTable<elemType>::insert(elemType a){
        int index = hash(a);
        bool check = true;

        if (table[index] == "empty"){//if the place is empty
                 table[index] = a;
                 length++;
        }else{//if it is not empty
            if(table[index] == a || length == HTsize){//if the element is already exist or if it is full
                check = false;
            }else{
                while (table[index] != "empty"){
                    index = (index +1)%HTsize;
                }
                table[index] = a;
                length++;
            }
        }
        return check;
}

template<class elemType>
elemType HashTable<elemType>::search(elemType a){
        elemType temp;
        bool check= false;
        for (int i = 0; i<HTsize;i++){
           if (table[i]==a){
               temp = table[hash(a)];
               table[i]="empty";
               check = true;
           }
        }
        if (check==false){
            throw"cannot find item";
        }
        length--;
        return temp;
}

#endif /* HASHTABLE_H_ */
