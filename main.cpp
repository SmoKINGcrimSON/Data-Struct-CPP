#include <iostream>
#include "DynamicArray/list.h"
#include "LinkedList/doublecirclelist.h"
#include "Trees/binarysearchtree.h"

using namespace ExtraMethodsDynamicArray;

int main(){
    
    BinarySearchTree<int>* nums = new BinarySearchTree<int>();
    try{
        nums->Insert(40);
        nums->Insert(20);
        nums->Insert(60);
        nums->Insert(10);
        nums->Insert(30);
        nums->Insert(50);
        nums->Insert(70);
        nums->Insert(80);
        nums->Insert(90);
        std::cout<<"Exist the number 30: "<<nums->Search(30)<<std::endl;
        std::cout<<"Exist the number 60: "<<nums->Search(60)<<std::endl;
        std::cout<<"Exist the number -10: "<<nums->Search(-10)<<std::endl;
        std::cout<<"Number of nodes of the tree: "<<nums->Size()<<std::endl;
        std::cout<<"Is the BST empty?: "<<nums->IsTreeEmpty()<<std::endl;
        std::cout<<"Min value of the BST: "<<nums->MinValue()<<std::endl;
        std::cout<<"Max value of the BST: "<<nums->MaxValue()<<std::endl;
        std::cout<<"Height of the tree: "<<nums->Height()<<std::endl;
        std::cout<<"Nodes print in-order:"<<std::endl;
        nums->PrintInOrder();
    }
    catch(const char* txtException){
        std::cout<<txtException<<std::endl;
    }
    delete nums;
    return 0;
}