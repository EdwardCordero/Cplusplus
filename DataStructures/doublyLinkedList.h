#pragma once

template <typename T>
struct LinkedNode
{
    LinkedNode() : prev(nullptr), next(nullptr), val(T{}) {};
    LinkedNode(const T& val): prev(nullptr), next(nullptr), val(val) {};
    LinkedNode<T>* prev;
    LinkedNode<T>* next;
    T val;
};

template <typename T>
class DoublyLinkedList
{
    public:
        DoublyLinkedList(): head(nullptr), tail(nullptr), count(0) {}

        void insert(LinkedNode<T>* newNode)
        {
            if(!head)
            {
                this->head = newNode;
                count++;
                return;
            }

            insertHelper(this->head, newNode);
            this->tail = newNode;
            count++;
            return;
        }

        void insert(T newVal)
        {
            LinkedNode<T>* newNode = new LinkedNode<T>(newVal);
            insert(newNode);
        }

        void print()
        {
            LinkedNode<T>* currentNode = this->head;
            int index = 0;
            while(currentNode)
            {
                T prevNodeVal = currentNode->prev ? currentNode->prev->val : T{};
                T nextNodeVal = currentNode->next ? currentNode->next->val : T{};

                std::cout << "Node {" << currentNode << "}" << " at i {" << index << "} val = " << currentNode->val << " Prev node address {" << currentNode->prev << "} val = " << prevNodeVal << " Next node address {" << currentNode->next << "} val = " << nextNodeVal << std::endl;
                currentNode = currentNode->next;
                index++;
            }
            std::cout << "Head val = " << this->head->val << std::endl;
            std::cout << "Tail val = " << this->tail->val << std::endl; 
        }

        LinkedNode<T>* DetectCycle()
        {
            LinkedNode<T>* slow = this->head;
            LinkedNode<T>* fast = this->head;

            while(fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast)
                {
                    slow = this->head;
                    while(slow != fast)
                    {
                        slow = slow->next;
                    }
                    return slow;
                }
            }

            return nullptr;
        }

    private:
        LinkedNode<T>* head;
        LinkedNode<T>* tail;
        int count;

        LinkedNode<T>* insertHelper(LinkedNode<T>*& currentNode, LinkedNode<T>* newNode)
        {
            if(currentNode == nullptr)
            {
                currentNode = newNode;
                return currentNode;
            }

            LinkedNode<T>* node = insertHelper(currentNode->next, newNode);
            node->prev = currentNode;
            return currentNode;
        }
};