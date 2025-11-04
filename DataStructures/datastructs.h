#pragma once
#include <iostream>
#include <initializer_list>
#include "..\Helperfunctions\helperfunctions.h"

template <typename T>
struct uVector { 
    T* data;
    size_t size;
    size_t capacity;

    uVector() : data(nullptr), size(0), capacity(0) {}

    uVector(std::initializer_list<T> list) : size(list.size()), capacity(list.size())
    {
        this->data = new T[size];
        size_t index = 0;
        for(auto value : list)
        {
            this->data[index] = value;
            index++;
        }
    }
    ~uVector()
    {
        if(this->data != nullptr)
        {
            delete this->data;
        }
        
        this->data = nullptr;
    }
    uVector(const uVector& other)
    {
        this->data = other.data;
        this->size = other.size;
        this->capacity = other.capacity;
    }

    uVector& operator=(const uVector& other)
    {
        if(data != nullptr)
        {
            delete data;
        }
        this->data = new T[other.capacity];
        for(int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
        this->size = other.size;
        this->capacity = other.capacity;

        return *this;
    }

    uVector(uVector&& other) noexcept
    {
        this->data = other.data;
        this->size = other.size;
        this->capacity = other.capacity;

        other.data = nullptr;
    }

    uVector& operator=(uVector&& other) noexcept
    {
        if(data != nullptr)
        {
            delete data;
        }

        this->data = other.data;
        this->size = other.size;
        this->capacity = other.capacity;

        other.data = nullptr;
        
        return *this;
    }

    void push(T newElem)
    {
        if(this->data == nullptr)
        {
            this->size = 0;
            this->capacity = 0;
        }
        size_t newSize = size + 1;
        if(newSize > capacity)
        {
            bool result = resizeArr(this->data, newSize);
            if(result)
            {   
                this->capacity = newSize;;
            }
            else{
                std::cerr << "Failed to push element to uVector" << std::endl;
                return;
            }
        }
        this->data[newSize - 1] = newElem;
        this->size++;
    }

    void pop()
    {
        if(this->size > 0 && this->data != nullptr)
        {
            this->data[size - 1] = NULL;
            this->size--;
        }
        else{
            this->size = 0;
            this->capacity = 0;
            this->data = nullptr;
            std::cout << "No elements to pop" << std::endl;
        }
    }
};