#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "treenode.h"
#include "../LinkedList/queue.h"

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
        //Find the max node in the binary search tree
        TreeNode<T>* MaxNode(TreeNode<T>** root){
            if((*root)->right == nullptr) return *root;
            else return MaxNode(&(*root)->right);
        }
        //Remove a node from the BST
        TreeNode<T>* Remove(TreeNode<T>** root, T value){
            if(*root == nullptr) throw "The element you try to remove doesn't exist in the BST.";
            //algorithm
            if(value < (*root)->value){
                (*root)->left = Remove(&(*root)->left, value);
            }
            else if(value > (*root)->value){
                (*root)->right = Remove(&(*root)->right, value);
            }
            else{
                if((*root)->left == nullptr && (*root)->right == nullptr){
                    delete *root;
                    *root = nullptr;
                }
                else if((*root)->left == nullptr){
                    TreeNode<T>* temp = *root;
                    *root = (*root)->right;
                    delete temp;
                    temp = nullptr;
                }
                else if((*root)->right == nullptr){
                    TreeNode<T>* temp = *root;
                    *root = (*root)->left;
                    delete temp;
                    temp = nullptr;
                }
                else{
                    TreeNode<T>* temp = MinNode(&(*root)->right);
                    (*root)->value = temp->value;
                    (*root)->right = Remove(&(*root)->right, temp->value);
                }
            }
            return *root;
        }
        //Height of the tree
        int Height(TreeNode<T>** root){
            if(*root == nullptr) return -1;
            int left = Height(&(*root)->left);
            int right = Height(&(*root)->right);
            return left > right? left + 1 : right + 1;
        }
        //number of leaves
        int Leaves(TreeNode<T>** root){
            if(*root == nullptr) return 0;
            int count = 0;
            if((*root)->left == nullptr && (*root)->right == nullptr) count++;
            count += Leaves(&(*root)->left);
            count += Leaves(&(*root)->right);
            return count;
        }
        //number of branches
        int Branches(TreeNode<T>** root){
            if(*root == nullptr) return 0;
            int count = 0;
            if((*root)->left != nullptr || (*root)->right != nullptr) count++;
            count += Leaves(&(*root)->left);
            count += Leaves(&(*root)->right);
            return count;
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
        //Lever travel print
        void LevelPrint(){
            TreeNode<T>* tempRoot = root;
            Queue<TreeNode<T>*>* values = new Queue<TreeNode<T>*>();
            values->Enqueue(tempRoot);
            while(!values->IsEmpty()){
                TreeNode<T>* temp = values->Top();
                if(temp->left != nullptr){
                    values->Enqueue(temp->left);
                }
                if(temp->right != nullptr){
                    values->Enqueue(temp->right);
                }
                std::cout<<temp->value<<std::endl;
                values->Dequeue();
            }
            delete values;
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
        //Find the max value in the binary search tree
        T MaxValue(){
            TreeNode<T>* max = MaxNode(&root);
            return max->value;
        }
        //Remove a node from the BST
        void Remove(T value){
            if(IsTreeEmpty()) throw "You can't remove nodes of an empty tree.";
            root = Remove(&root, value);
            size--;
        }
        //Height of the tree
        int Height(){
            return Height(&root);
        }
        //number of leaves
        int Leaves(){
            return Leaves(&root);
        }
        //number of branches
        int Branches(){
            return Branches(&root);
        }
};

#endif