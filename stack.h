#ifndef STACK_H
#define STACK_H

#include <vector>

template <class T>
class Stack{
    private:
        std::vector<T> data;
    public:
        bool isEmpty();
        T top();
        void push(T value);
        bool pop();
};
#endif