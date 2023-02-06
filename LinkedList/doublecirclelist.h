#ifndef DOUBLECIRCLELIST_H
#define DOUBLECIRCLELIST_H
#include "node.h"

template<typename T>
class DoubleCircleLinkedList{
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        DoubleCircleLinkedList(){
            head = nullptr;
            tail = head;
        }
        void InsertAtTheEnd(T value){
            Node<T>* newNode = new Node<T>(value);
            if(head == nullptr){
                head = newNode;
                tail = head;
            }
            else{
                tail->next = newNode;
                newNode->previous = tail;
                tail = newNode;
            }
            tail->next = head;
            head->previous = tail;
        }
        void InsertAtFront(T value){
            Node<T>* newNode = new Node<T>(value);
            if(head == nullptr){
                head = newNode;
                tail = head;
            }
            else{
                newNode->next = head;
                head->previous = newNode;
                head = newNode;
            }
            tail->next = head;
            head->previous = tail;
        }
        void PrintForward(){
            if(head == nullptr) throw "The double circle linked list is empty";
            Node<T>* i = head;
            do{
                std::cout<<i->value<<std::endl;
                i = i->next;
            }
            while(i != head);
        }
        void PrintBackward(){
            if(head == nullptr) throw "The double circle linked list is empty.";
            Node<T>* i = tail;
            do{
                std::cout<<i->value<<std::endl;
                i = i->previous;
            }
            while(i != tail);
        }
};

#endif