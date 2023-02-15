#ifndef QUEUE_H
#define QUEUE_H
#include "simplenode.h"

template<typename T>
class Queue{
    private:
        SimpleNode<T>* head;
        SimpleNode<T>* tail;
        int size;
    public:
        Queue(){
            head = nullptr;
            tail = head;
        }
        ~Queue(){
            while(!IsEmpty()){
                Dequeue();
            }
        }
        int Size() const{
            return size;
        }
        bool IsEmpty() const{
            return size == 0;
        }
        void Enqueue(T value){
            SimpleNode<T>* newNode = new SimpleNode<T>(value);
            if(head == nullptr){
                head = newNode;
                tail = head;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }
        void Dequeue(){
            if(IsEmpty()) throw "can't remove a node from an empty queue.";
            if(head == tail){
                delete head;
                head = nullptr;
                tail = head;
            }
            else{
                SimpleNode<T>* temp = head;
                head = head->next;
                delete temp;
                temp = nullptr;
            }
            size--;
        }
        T Top(){
            return !IsEmpty()? head->value : throw "Queue is empty.";
        }
        void PrintValues(){
            if(IsEmpty()) throw "You can't print values of an empty queue.";
            for(SimpleNode<T>* i = head; i != nullptr; i = i->next){
                std::cout<<i->value<<std::endl;
            }
        }
};

#endif