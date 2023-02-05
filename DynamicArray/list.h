#ifndef LIST_H
#define LIST_H
#include <iostream>

template<class T>
class List{
    private:
        T* array;
        int size;
        int capacity;
        void Grow(){
            int newCapacity = capacity * 2;
            T* newArray = new T[newCapacity];
            for(int i = 0; i < size; i++){
                *(newArray + i) = *(array + i); 
            }
            delete array;
            array = nullptr;
            array = newArray;
            capacity = newCapacity;
        }
        void Shrink(){

        }
    public:
        List(){
            this->capacity = 4;
            this->size = 0;
            array = new T[capacity];
        }
        ~List(){
            delete array;
            array = nullptr;
            if(array == nullptr){
                std::cout<<"List was deleted."<<std::endl;
            }
        }
        int Size() const{
            return size;
        }
        int Capacity() const{
            return capacity;
        }
        void Insert(T value){
            if(size >= capacity){
                Grow();
            }
            array[size] = value;
            size++;
        }
        void InsertAt(int index, T value){
            //
        }
        bool IsEmpty() const{
            return size == 0;
        }
        T elementAt(int index) const{
            if(index >= size){
                throw "Index can't be larger than size.";
            }
            return array[index];
        }
};

namespace ExtraMethodsDynamicArray{
        template<typename T>
        std::ostream& operator<<(std::ostream& COUT, const List<T>& list){
            if(list.IsEmpty()) throw "The list is empty.";
            for(int i = 0; i < list.Size(); i++){
                COUT<<list.elementAt(i)<<std::endl;
            }
            return COUT;
        }
};

#endif