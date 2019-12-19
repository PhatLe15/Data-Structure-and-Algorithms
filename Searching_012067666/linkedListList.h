#ifndef sortedLinkedList_h
#define sortedLinkedList_h
#include<iostream>

using namespace std;
template<typename T>
struct Node{

    T data;
    Node *next;

};
template<typename T>

class linkedListList{
private:

    Node<T> *head;
    Node<T> *tail;
    int max;
    int size;

public:
    //need to create a accesor to the head to use recursion
Node<T>* node_accessor(){
    return head;
}
    linkedListList(int s = 5)   //constructor
    {
        head = NULL;
        tail = NULL;
        max = s;
        size = 0;
    }
    ~linkedListList()   //destructor
    {
    }
bool isEmpty() const
    {
        return size==0;
    }
bool isFull() const{
        return size == max;
    }
int listSize() const{
        return size;
    }
int maxListSize() const{
        return max;
    }
void print(){
        Node<T> *current = head;
        while(current != NULL){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
bool isItemAtEqual(int pos, T data){
        if(pos >= size){
            cout<<"invalid Position"<<endl;
            return false;
        }
        Node<T> *current = head;
        int currentPosition = 0;
        while(current != NULL && currentPosition < pos){
            current = current->next;
            currentPosition++;
        }
        return current->data == data;
    }
void insertAt(int pos, T data){
        if(pos > size){
            cout<<"cannot insert at "<<pos<<"\t list size is "<<size<<endl;
            return;
        }
        if(isFull()){
            cout<<"list is full"<<endl;
            return;
        }
        Node<T> *temp = (Node<T>*) malloc(sizeof(Node<T>));
        temp->data = data;
        temp->next = NULL;
        if(pos == 0){
            if(head == NULL){
                head = tail = temp;
                return;
            }
            else{
                temp->next = head;
                head = temp;
            }
            size++;
            return ;
        }

        if(pos == size){
            insertEnd(data);
            return;
        }
        Node<T> *current = head;
        Node<T> *prev = NULL;
        int currentPosition = 0;
        while(current != NULL && currentPosition < pos){
            prev = current;
            current = current->next;
            currentPosition++;
        }
        prev->next = temp;
        temp->next = current;
        size++;
    }
void insertEnd(T data){
        Node<T> *temp = (Node<T>*) malloc(sizeof(Node<T>));
        temp->data = data;
        temp->next = NULL;

        if(tail == NULL){
            head = tail = temp;
        }
        tail->next = temp;
        tail = temp;
        size++;
    }
void removeAt(int pos){
        if(isEmpty()){
            return;
        }
        if(pos >= size){
            return ;
        }
        if(pos == 0){
            head = head->next;
            if(head == NULL)
                tail = NULL;
            size--;
            return;

        }
        Node<T> *current = head;
        Node<T> *prev = NULL;
        int currentPosition = 0;
        while(current != NULL && currentPosition < pos){
            prev = current;
            current = current->next;
            currentPosition++;
        }
        if(current->next == NULL){
            prev->next = NULL;
            tail = prev;
            size--;
            return;
        }
        prev->next = current->next;
        size--;
    }
T retreiveAt(int pos){
        if(pos == 0){
            return head->data;
        }
        if(pos == size-1){
            return tail->data;
        }
        if(pos >= size){
            cout<<"not enough elements in the list:"<<endl;
            return -1;
        }
        Node<T> *current = head;
        int currentPosition = 0;
        while(current != NULL && currentPosition < pos){
            current = current->next;
            currentPosition++;
        }
        return current->data;
    }
void replaceAt(int pos, T data){
        if(pos == 0){
            head->data = data;
            return ;
        }
        if(pos == size-1){
            tail->data = data;
            return;
        }
        if(pos >= size){
            cout<<"not enough elements in the list: "<<endl;
            return ;
        }
        Node<T> *current = head;
        int currentPosition = 0;
        while(current != NULL && currentPosition < pos){
            current = current->next;
            currentPosition++;
        }
        current->data = data;
    }
void clearList(){
        while(head != NULL){
            Node<T> *current = head;
            head = head->next;
            delete current;
        }
        size = 0;
    }
void operator =(const linkedListList &list){
        size = list.listSize();
        max = list.maxListSize();
        head = NULL;
        tail = NULL;
        Node<T> *current = list.head;
        while(current!= NULL){
            insertEnd(current->data);
            current = current->next;
        }
    }
bool seqSearchIter (T element){
    struct Node<T> *current = head;
    while(current!=NULL){
        if(current->data==element){
            return true;
        }
        current=current->next;
    }
    return false;
}

bool seqSearchRec(Node<T> *head,T element){
    if(head==NULL){//base case
        return false;
    }if(head->data==element){//if it is in the current node
        return true;
    }
    return seqSearchRec(head->next, element);
}
};
#endif /* sortedLinkedList_h */
