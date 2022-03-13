#include "stack.h"

/*
 * @brief Returns if stack is empty
 * @return true: Stack is empty
 *         false: Stack has elements
 */
template <class T>
bool Stack<T>::isEmpty(){
    return data.empty();
}


/*
 * @brief Returns the last element in the stack
 * @return T: last element's data
 */
template <class T>
T Stack<T>::top(){
    return data.back();
}

/*
 * @brief Adds element to the end of the stack
 * @param value: Data to be added at the end of the stack
 */
template <class T>
void Stack<T>::push(T value){
    data.push_back(value);
}

/*
 * @brief Removes the last element in the stack
 * @return true: Successfully removed an element
 *         false: Stack is empty, didn't remove anything
 */
template <class T>
bool Stack<T>::pop(){
    if(!isEmpty()){
        data.pop_back();
        return true;
    }
    return false;
}