/*
 * clockType.h
 *
 *  Created on: Feb 2, 2019
 *      Author: Phat Le
 */

#ifndef TreeHeap_H_
#define TreeHeap_H_

#include "arrayQueue.h"
#include "maxheap.h"
#include <iostream>
using namespace std;

template<typename elemType>
struct Node{

    elemType data = NULL;
    Node<elemType> *lchild = NULL;
    Node<elemType> *rchild = NULL;

};

template<class elemType>
class TreeHeap
{
public:
      TreeHeap();
      ~TreeHeap();
      void print(Node<elemType> *p);
      const Node<elemType>* dfs (elemType, Node<elemType> *p);
      const Node<elemType>* bfs (elemType);
      const Node<elemType>* search (elemType);
      void buildheap(elemType array, unsigned int size);
private:
      void heapify();
      int maxSize;
      int length;
      Node<elemType>* tree;
      Node<elemType>* root;

};

//constructor
template<class elemType>
TreeHeap<elemType>::TreeHeap(){
        maxSize = 10;
        length = 0;
        root = NULL;
        tree = new Node<elemType>[maxSize];

}

//Destructor
template<class elemType>
TreeHeap<elemType>::~TreeHeap(){
        delete []tree;
}

template<class elemType>
//hash function
void TreeHeap<elemType>::print(Node<elemType> *p){
        if (p!= NULL){
            cout<<p->data<<" ";
            print(p->lchild);
            print(p->rchild);
        }

}

//buildheap
template<class elemType>
void TreeHeap<elemType>::buildheap(elemType array, unsigned int size){

        for (int i = 0; i<size; i++){
            tree[i]->data = array[i];
        }
        heapify();
        length = size;
}



template<class elemType>
const Node<elemType>* TreeHeap<elemType>::dfs(elemType a, Node<elemType> *p){
        if (root->data!=NULL){//attempt to use indorder to search starting
            dfs(a,root->lchild);//from the root
            if(p->data==a){
                return *p;
            }
            inorder(p->rchild);
        }else{
            return NULL;
        }
}

template<class elemType>
const Node<elemType>* TreeHeap<elemType>::bfs(elemType a){
        arrayQueue<elemType> q;
        q.enqueue(root->data);//attemp to use enqueue for bfs search
        Node<elemType> n;
        while (!q.isEmpty()){
            n = q.dequeue();
            if(n.lchild){
                q.enqueue(n.lchild);
            }if (n.rchild){
                q.enqueue(n.rchild);
            }if(n.data==a){//if found return the reference constant
                return *n;
            }
        }
        return NULL;
}

template<class elemType>
const Node<elemType>* TreeHeap<elemType>::search(elemType a){
        bool found = false;
        Node<elemType> n = root;
        while (!found){
            if(n->data == a){//follow heap tree binary search
                return true;
            }else if(n->data > a){// if element is on the left side
                n = n.lchild;
            }else if (n->data <a){
                n = n.rchild;
            }
        }
        return *n;
}

template<class elemType>
void TreeHeap<elemType>::heapify(){
        for(int i = 0; i<length; i++){
            tree[i]->lchild = 2*i+1<length?tree[2*i+1]:NULL;
            tree[i]->rchild = 2*i+2<length?tree[2*i+2]:NULL;
        }
        root=tree[0];

}

#endif /* TreeHeap_H_ */
