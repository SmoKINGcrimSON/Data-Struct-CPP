#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

template<typename T>
class TreeNode{
    public:
        T value;
        TreeNode<T>* left;
        TreeNode<T>* right;
        TreeNode(){
            left = nullptr;
            right = nullptr;
        }
        TreeNode(T value){
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

#endif