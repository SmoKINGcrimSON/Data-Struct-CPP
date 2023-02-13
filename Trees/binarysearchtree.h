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
        //Search the existence of an element in the tree
        bool Search(TreeNode<T>** root, T value){
            if(*root == nullptr) return false;
            else if(value < (*root)->value){
                return Search(&(*root)->left, value);
            }
            else if(value > (*root)->value){
                return Search(&(*root)->right, value);
            }
            else return true;
        }
        //Find the min node in the binary search tree
        TreeNode<T>* MinNode(TreeNode<T>** root){
            if((*root)->left == nullptr) return *root;
            else return MinNode(&(*root)->left);
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
            size++;
        }
        //In-order travel print
        void PrintInOrder(){
            if(IsTreeEmpty()) throw "You can't print an empty BST.";
            PrintInOrder(&root);
        }
        //Search the existence of an element in the tree
        bool Search(T value){
            return Search(&root, value);
        }
        //Find the min value in the binary search tree
        T MinValue(){
            if(IsTreeEmpty()) throw "You can't find the min value in an empty BST.";
            TreeNode<T>* min = MinNode(&root);
            return min->value;
        }
};

#endif