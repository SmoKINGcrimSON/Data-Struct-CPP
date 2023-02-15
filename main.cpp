#include <iostream>
#include "DynamicArray/list.h"
#include "LinkedList/doublecirclelist.h"
#include "Trees/binarysearchtree.h"

using namespace ExtraMethodsDynamicArray;

int main(){
    BinarySearchTree<int>* nums = new BinarySearchTree<int>();
    nums->Insert(40);
    nums->Insert(30);
    nums->Insert(50);
    nums->Insert(20);
    nums->Insert(35);
    nums->Insert(45);
    nums->Insert(60);
    nums->Insert(10);
    nums->Insert(70);
    nums->LevelPrint();
    delete nums;
    return 0;
}