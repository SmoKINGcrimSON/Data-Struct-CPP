#include <iostream>
#include "DynamicArray/list.h"
#include "LinkedList/doublecirclelist.h"

using namespace ExtraMethodsDynamicArray;

int main(){
    
    DoubleCircleLinkedList<int>* nums = new DoubleCircleLinkedList<int>();
    try{
        nums->InsertAtTheEnd(123);
        nums->InsertAtFront(333);
        nums->InsertAtFront(444);
        std::cout<<"Print forward:"<<std::endl;
        nums->PrintForward();
        std::cout<<"Print backward:"<<std::endl;
        nums->PrintBackward();
    }
    catch(const char* txtException){
        std::cout<<txtException<<std::endl;
    }
    delete nums;
    return 0;
}