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
        void InsertAfter(T value, T newValue){
            if(head == nullptr) throw "The double circle Linked List is empty.";
            Node<T>* i = head;
            do{
                if(i->value == value){
                    if(tail->value == value){
                        InsertAtTheEnd(newValue);
                    }
                    else{
                        Node<T>* newNode = new Node<T>(newValue);
                        i->next->previous = newNode;
                        newNode->next = i->next;
                        i->next = newNode;
                        newNode->previous = i;
                    }
                    return;
                }
                else{
                    i = i->next;
                }
            }
            while(i != head);
            throw "The value doesn't exist in the double circle linked list.";
        }
        void InsertBefore(T value, T newValue){
            if(head == nullptr) throw "The double circle linked list is empty.";
            Node<T>* i = head;
            do{
                if(i->value == value){
                    if(head->value == value){
                        InsertAtFront(newValue);
                    }
                    else{
                        Node<T>* newNode = new Node<T>(newValue);
                        i->previous->next = newNode;
                        newNode->previous = i->previous;
                        i->previous = newNode;
                        newNode->next = i;
                    }
                    return;
                }
                else{
                    i = i->next;
                }
            }
            while(i != head);
            throw "The value doesn't exist in the double circle linked list.";
        }
        void Remove(T value){
            if(head == nullptr) throw "You can't remove element from and empty list.";
            Node<T>* i = head;
            do{
                if(i->value == value){
                    if(head == tail){
                        head = nullptr;
                        tail = head;
                    }
                    else if(head->value == value){
                        head = head->next;
                        tail->next = head;
                        head->previous = tail;
                    }
                    else if(tail->value == value){
                        tail = tail->previous;
                        tail->next = head;
                        head->previous = tail;
                    }
                    else{
                        i->previous->next = i->next;
                        i->next->previous = i->previous;
                    }
                    return;
                }
                else{
                    i = i->next;
                }
            }
            while(i != head);
            throw "The value doesn't exist to be removed.";
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