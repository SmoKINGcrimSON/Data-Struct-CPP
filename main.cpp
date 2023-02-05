#include <iostream>
#include "DynamicArray/list.h"

using namespace ExtraMethodsDynamicArray;

int main(){
    
    List<int>* nums = new List<int>();
    try{
        /*
        nums->Insert(123);
        nums->Insert(333);
        nums->Insert(444);
        nums->Insert(555);
        nums->Insert(55654);
        nums->Insert(-123);
        nums->Insert(333);
        nums->Insert(999);
        */
        std::cout<<"Size: "<<nums->Size()<<std::endl;
        std::cout<<"Capacity: "<<nums->Capacity()<<std::endl;
        std::cout<<"Is empty: "<<nums->IsEmpty()<<std::endl;
        std::cout<<*nums<<std::endl;
    }
    catch(const char* txtException){
        std::cout<<txtException<<std::endl;
    }
    delete nums;
    return 0;
}