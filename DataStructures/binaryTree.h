#pragma once

template <typename T>
struct node
{
    T data;
    node<T>* left;
    node<T>* right;

    node() : data(T{}), left(nullptr), right(nullptr) {};
};

template<typename T> 
class BinaryTree
{
    public:
        node<T>* head;
        BinaryTree() : head(nullptr) {};

        void insert(T value)
        {
            if(head == nullptr)
            {
                
            }
        }

    private:
};