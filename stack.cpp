#include "stack.h"

template <class T>
bool Stack<T>::isEmpty(){
    return data.empty();
}

template <class T>
T Stack<T>::top(){
    return data.back();
}

// Adds an element to our stack
template <class T>
void Stack<T>::push(T value){
    data.push_back(value);
}

// Remove the last element in our stack
template <class T>
bool Stack<T>::pop(){
    if(!isEmpty()){
        data.pop_back();
        return true;
    }
    return false;
}