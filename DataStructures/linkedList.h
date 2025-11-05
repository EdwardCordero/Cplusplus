#pragma once
#include "node.h"

template <typename T>
class LinkedList
{
    public:
        LinkedList() : head(nullptr), tail(nullptr) {};
        ~LinkedList() {

        };

        void insert(Node<T>* newNode, int nodeIndex = NULL)
        {
            if(nodeIndex == NULL)
            {
                tail->next = newNode;
                this->tail = newNode;
                return;
            }
        }

        Node<T>* head;
        Node<T>* tail;
    private:
};