#include <iostream>
#include "..\HelperFunctions\helperfunctions.h"
#include "..\DataStructures\person.h"
#include "..\DataStructures\linkedList.h"
#include "..\DataStructures\doublyLinkedList.h"
#include "..\DataStructures\binaryTree.h"

void runLinkedListExample()
{
    LinkedList<int> list;
    list.insert(0);
    list.insert(4);
    list.insert(5);
    list.insert(1, 1);
    list.insert(2, 2);
    list.insert(6);

    list.print();

    list.remove(2);

    list.print();

    list.reverseRecursively();
    list.print();
}

template <typename T>
void printAny(DoublyLinkedList<T>& value)
{
    LinkedNode<T>* node = value.head;
    while(node != nullptr)
    {
        std::cout << node->val << (node->next == nullptr ? "" : "-->");
        node = node->next;
    }
    std::cout << std::endl;
}


// merging values into l1 to save memory
// the resulting merged list will be sorted in ascending order
template<typename T>
void mergeTwoSortedDLL(DoublyLinkedList<T>& l1, DoublyLinkedList<T>& l2)
{
    LinkedNode<T>* node1 = l1.head;
    LinkedNode<T>* node2 = l2.head;
    LinkedNode<T>* mergedHead = nullptr;
    LinkedNode<T>* currentNode = nullptr;

    if(node1->val >= node2->val)
    {
        mergedHead = node2;
        node2 = node2->next;
    }
    else{
        mergedHead = node1;
        node1 = node1->next;
    }
    currentNode = mergedHead;

    while(node1 != nullptr && node2 != nullptr)
    {
        LinkedNode<T>* temp = nullptr;
        if(node1->val >= node2->val)
        {
            temp = node2;
            node2 = node2->next;
        }
        else {
            temp = node1;
            node1 = node1->next;
        }

        currentNode->next = temp;
        temp->prev = currentNode;
        currentNode = currentNode->next;
    }

    while(node1 != nullptr)
    {
        currentNode->next = node1;
        currentNode->next->prev = currentNode;
        currentNode = currentNode->next;
        node1 = node1->next;
    }
    while(node2 != nullptr)
    {
        currentNode->next = node2;
        currentNode->next->prev = currentNode;
        currentNode = currentNode->next;
        node2 = node2->next;
    }

    l1.head = mergedHead;
    l1.tail = currentNode;
    
    l2.head = nullptr;
    l2.tail = nullptr;
}

void runDoublyLinkedListExample()
{
    DoublyLinkedList<int>* list = new DoublyLinkedList<int>;
    list->insert(1);
    list->insert(4);
    list->insert(10);

    std::cout << "List A: " << std::endl;
    printAny<int>(*list);

    DoublyLinkedList<int>* list1 = new DoublyLinkedList<int>;
    list1->insert(0);
    list1->insert(2);
    list1->insert(8);
    std::cout << "List B: " << std::endl;
    printAny<int>(*list1);

    mergeTwoSortedDLL(*list, *list1);
    std::cout << "MergedList: " << std::endl;
    printAny(*list);
}

int main(int argsc, char** argsv)
{
    runDoublyLinkedListExample();
    node<int> nodeA = node<int>();
    int t= 0;
}