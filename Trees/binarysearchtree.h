#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "treenode.h"

template<class T>
class BinarySearchTree{
    private:
        TreeNode<T>* root;
        int size;
        //Insert Node
        TreeNode<T>* Insert(TreeNode<T>** root, T value){
            if(*root == nullptr){
                *root = new TreeNode<T>(value);
            }
            else if(value < (*root)->value){
                (*root)->left = Insert(&(*root)->left, value);
            }
            else{
                (*root)->right = Insert(&(*root)->right, value);
            }
            return *root;
        }
        //In-order travel print
        void PrintInOrder(TreeNode<T>** root){
            if(*root == nullptr) return;
            PrintInOrder(&(*root)->left);
            std::cout<<(*root)->value<<std::endl;
            PrintInOrder(&(*root)->right);
        }
    public:
        BinarySearchTree(){
            root = nullptr;
        }
        int Size() const{
            return size;
        }
        int IsTreeEmpty() const{
            return size == 0;
        }
        //Insert Node
        void Insert(T value){
            root = Insert(&root, value);
        }
        //In-order travel print
        void PrintInOrder(){
            PrintInOrder(&root);
        }
};

#endif