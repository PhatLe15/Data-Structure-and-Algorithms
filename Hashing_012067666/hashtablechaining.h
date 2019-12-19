/*
 * clockType.h
 *
 *  Created on: Feb 2, 2019
 *      Author: Phat Le
 */

#ifndef HashTableChaining_H_
#define HashTableChaining_H_

#include <iostream>
using namespace std;

template<class elemType>
class HashTableChaining
{
public:
      HashTableChaining();
      ~HashTableChaining();
      int hash(elemType);
      void print();
      bool insert(elemType);
      elemType search(elemType);

private:
      static const int HTsize = 5;
      int length;
      //elemType *table;
      struct item{
              elemType element;
              item*next;
      };

      item* table[HTsize];
};

//constructor
template<class elemType>
HashTableChaining<elemType>::HashTableChaining(){
        length = 0;
        for (int i=0; i< HTsize; i++){
            table[i] = new item;
            table[i]->element = "empty";
            table[i]->next = NULL;
        }
}

//Destructor
template<class elemType>
HashTableChaining<elemType>::~HashTableChaining(){
        //delete []table; I dont use dynamic memory allocation so I dont need this.
}

template<class elemType>
//hash function
int HashTableChaining<elemType>::hash(elemType key){
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
void HashTableChaining<elemType>::print(){
     cout<<"Hash table list is: "<<endl;
     for (int i =0; i<HTsize;i++){
         /*
         item* temp = table[i];
         while(temp->next != NULL){
             if (temp->element == "empty"){
                 temp = temp->next;
             }else{
                 cout<<temp->element<<" ";
                 temp= temp->next;
             }
         }*/
         //cout<<endl;
         if(table[i]->element != "empty"){//if table is not empty
             cout<<table[i]->element;
             item* temp = table[i];
             while(temp->next != NULL){
                 if (temp->next->element != "empty"){//if it is not empty
                     cout<<"->"<<temp->next->element;
                 }
                 temp = temp->next;
             }
             cout<<endl;
         }
     }
     if(length == 0){
         cout<<"table is tempty!"<<endl;
     }

}

//insert
template<class elemType>
bool HashTableChaining<elemType>::insert(elemType a){
        int index = hash(a);

        if (table[index]->element == "empty"){//if the place is empty
                 table[index]->element = a;
                 length++;
        }else{//if it is not empty
            if(table[index]->element == a ){
                return false;
            }else{
                item* temp = table[index];
                item* new_item = new item;//create new item
                while(temp->next != NULL){
                    temp = temp->next;

                }
                new_item->element = a;
                new_item->next = NULL;
                temp->next = new_item;
                length++;
            }
        }
       return true;
}

template<class elemType>
elemType HashTableChaining<elemType>::search(elemType a){

        elemType temp;
        bool yes = false;
        item* check = table[hash(a)];
        while(yes==false){// find it location
            if (check->element == a){
                temp = check->element;
                check->element="empty";
                length--;
                yes = true;
            }
            check = check->next;
        }
        if (yes == false){
            throw"cannot find the searching value";
        }


        return temp;
}

#endif /* HashTableChaining_H_ */
