#ifndef NODE_H
#define NODE_H
#include <iostream>

template<typename T>
class Node{
    public:
        T value;
        Node<T>* next;
        Node<T>* previous;
        Node(){
            next = nullptr;
            previous = nullptr;
        }
        Node(T value){
            this->value = value;
            next = nullptr;
            previous = nullptr; 
        }
};

#endif