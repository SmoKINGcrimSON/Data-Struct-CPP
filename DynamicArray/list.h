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
            int newCapacity = capacity / 2;
            T* newArray = new T[newCapacity];
            for(int i = 0; i < size; i++){
                *(newArray + i) = *(array + i); 
            }
            delete array;
            array = nullptr;
            array = newArray;
            capacity = newCapacity;
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
            if(index >= size) throw "Invalid index";
            if(size >= capacity) Grow();
            for(int i = size; i > index; i--){
                array[i] = array[i - 1];
            }
            array[index] = value;
            size++;
        }
        void Remove(T value){
            if(IsEmpty()) throw "The dynamic array is empty";
            for(int i = 0; i < size; i++){
                if(array[i] == value){
                    for(int j = i; j < size - 1; j++){
                        array[j] = array[j + 1];
                    }
                    array[size - 1] = 0;
                    size--;
                    if(size <= (capacity/3) && size >= 1){
                        Shrink();
                    }
                    return;
                }
            }
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