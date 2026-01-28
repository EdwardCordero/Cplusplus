#pragma once
#include "node.h"

template <typename T>
class LinkedList
{
    public:
        LinkedList() : head(nullptr), tail(nullptr), count(0) {};
        ~LinkedList() {
            cleanup(this->head);
        };

        Node<T>* traverseInsert(Node<T>* currentNode, Node<T>* nodeToInsert, int &index)
        {
            if(index == 0)
            {
                nodeToInsert->next = currentNode;
                return nodeToInsert;
            }
            else{
                index--;
                Node<T>* newNext = traverseInsert(currentNode->next, nodeToInsert, index);
                currentNode->next = newNext;
            }
            return currentNode;
        }

        void remove(int index)
        {
            if(index < 0 || index >= this->count) { return; }

            Node<T>* currNode = this->head;
            Node<T>* prevNode = nullptr;
            while(index != 0)
            {
                prevNode = currNode;
                currNode = currNode->next;
                index--;
            }  
            
            if(currNode == this->head)
            {
                Node<T>* temp = this->head;
                this->head = this->head->next;
                delete temp;
                return;
            }

            Node<T>* newNext = currNode->next;
            prevNode->next = newNext;
            delete currNode;

            this->count--;
        }

        void insert(T newNodeValue, int nodeIndex = -1)
        {
            Node<T>* newNode = new Node<T>();
            newNode->value = newNodeValue;

            insert(newNode, nodeIndex);
        }

        void insert(Node<T>* newNode, int nodeIndex = -1)
        {
            if(this->head == nullptr)
            {
                this->head = this->tail = newNode;
                count++;
                return;
            }
            if(nodeIndex == -1)
            {
                this->tail->next = newNode;
                this->tail = newNode;
            }
            else{
                // iterate thru till i = nodeIndex, start from head @ 0
                traverseInsert(this->head, newNode, nodeIndex);
            }

            count++;
        }

        void print()
        {
            Node<T>* nextNode = this->head;

            while(nextNode != nullptr)
            {
                std::cout << &nextNode << " Node = " << nextNode->value << std::endl;
                nextNode = nextNode->next;
            }
        }

        void cleanup(Node<T>* &nextNode)
        {
            if(nextNode == nullptr)
            {
                return;
            }
            if(nextNode->next != nullptr)
            {
                cleanup(nextNode->next);
            }
            delete nextNode;
        }
        
        // void flip(Node<T>* currentNode, Node<T>* prevNode)
        // {
        //     if(currentNode == nullptr)
        //     {
        //         return;
        //     }

        //     flip(currentNode->next, currentNode);

        //     currentNode->next = prevNode;
        //     return;
        // }

        void reverseRecursively()
        {
            reverseRecursivelyHelper(this->head, nullptr);
            
            Node<T>* temp = this->tail;
            this->tail = this->head;
            this->head = temp;
        }

        void reverseIteratively()
        {
            Node<T>* prevNode = nullptr;
            Node<T>* currNode = this->head;
            Node<T>* temp = nullptr;
            this->tail = this->head;
            while(currNode)
            {
                temp = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = temp;
            }

            this->head = prevNode;
        }

    private:
        Node<T>* head;
        Node<T>* tail;
        int count;

        void reverseRecursivelyHelper(Node<T>* currentNode, Node<T>* prevNode)
        {
            if(currentNode == nullptr)
            {
                return;
            }

            reverseRecursivelyHelper(currentNode->next, currentNode);

            currentNode->next = prevNode;
            return;
        }
};