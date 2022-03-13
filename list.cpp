#include "list.h"

template <class T>
List<T>::List(){
    first = nullptr;
    last = nullptr;
    length = 0;
}

template <class T>
bool List<T>::isEmpty(){
    return length == 0;
}

template <class T>
void List<T>::insert(T value){
    Node<T>* p = new Node<T>(value);
    
    if(isEmpty()){
        first = p;
        last = p;
    }
    else
        last->next = p;
}

// Remove 
template <class T>
void List<T>::remove(){
    
}