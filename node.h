#ifndef NODE_H
#define NODE_H

#include <iostream> // Allows usage of NULL and nullptr

template <class T>
struct Node{
    T data;
    Node<T>* next;
    Node(T val = (T)NULL, Node<T>* n = nullptr) : data(val), next(n){}
    ~Node(){
        data = (T)NULL;
        next = nullptr;
    }
}
#endif