#include <iostream>
#include "..\HelperFunctions\helperfunctions.h"
#include "..\DataStructures\person.h"
#include "..\DataStructures\linkedList.h"
#include "..\DataStructures\doublyLinkedList.h"

void runDoublyLinkedListExample()
{
    DoublyLinkedList<int> list;
    list.insert(0);
    list.insert(4);
    list.insert(10);
    list.print();
}

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

int main(int argsc, char** argsv)
{
    runDoublyLinkedListExample();
}