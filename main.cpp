#include <iostream>
#include "DynamicArray/list.h"
#include "LinkedList/doublecirclelist.h"
#include "Trees/binarysearchtree.h"

using namespace ExtraMethodsDynamicArray;

int main(){
    
    BinarySearchTree<int>* nums = new BinarySearchTree<int>();
    try{
        /*
        nums->Insert(40);
        nums->Insert(20);
        nums->Insert(60);
        nums->Insert(10);
        nums->Insert(30);
        nums->Insert(50);
        nums->Insert(70);
        nums->Insert(80);
        */
        std::cout<<"Exist the number 30: "<<nums->Search(30)<<std::endl;
        std::cout<<"Exist the number 80: "<<nums->Search(80)<<std::endl;
        std::cout<<"Exist the number -10: "<<nums->Search(-10)<<std::endl;
        std::cout<<"Number of nodes of the tree: "<<nums->Size()<<std::endl;
        std::cout<<"Is the BST empty?: "<<nums->IsTreeEmpty()<<std::endl;
        nums->PrintInOrder();
    }
    catch(const char* txtException){
        std::cout<<txtException<<std::endl;
    }
    delete nums;
    return 0;
}