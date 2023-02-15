#ifndef SIMPLENODE_H
#define SIMPLENODE_H
#include <iostream>
template<typename T>
class SimpleNode{
    public:
        T value;
        SimpleNode<T>* next;
        SimpleNode(){
            this->next = nullptr;
        }
        SimpleNode(T value){
            this->value = value;
            this->next = nullptr;
        }
};

#endif