#ifndef LIST_H
#define LIST_H

#include "node.h"

template <class T>
class List{
    private:
        Node<T>* first;
        Node<T>* last;
        int length;
    public:
        List(); // Default constructor
        bool isEmpty();
        void insert(T);
        bool remove();
        bool remove(T);
}
#endif