#pragma once
#include <iostream>
#include "..\HelperFunctions\helperfunctions.h"

struct Person{
    char* name;

    Person() : name(nullptr) {};
    Person(const char* newName) { 
        int len = stringLen(newName);
        this->name = (char*)std::malloc(len + 1);

        for(int i = 0; i <= len; i++)
        {
            this->name[i] = newName[i];
        }
    };
    Person(const Person &other)
    {
        int len = stringLen(other.name);
        this->name = (char*)std::malloc(len + 1);
        for(int i = 0; i <= len; i++)
        {
            this->name[i] = other.name[i];
        }
    }
    Person(Person&& other) noexcept : name(other.name){
        other.name = nullptr;
    };
    ~Person() {
        if(this->name != nullptr)
        {
            std::free(this->name);
        }
        this->name = nullptr;
    }

    Person& operator=(const Person &other)
    {
        if(this->name != nullptr)
        {
            std::free(this->name);
        }
        size_t len = stringLen(other.name);
        this->name = (char*)std::malloc(len + 1);
        for(int i = 0; i <= len; i++)
        {
            this->name[i] = other.name[i];
        }

        return *this;
    }

    Person& operator=(const char* newName){
        if(this->name != nullptr)
        {
            std::free(this->name);
        }
        int len = stringLen(newName);
        this->name = (char*)std::malloc(len + 1);

        for(int i = 0; i <= len; i++)
        {
            this->name[i] = newName[i];
        }

        return *this;
    }

    Person& operator=(Person&& other)
    {
        if(this->name != nullptr)
        {
            std::free(this->name);
        }
        this->name = other.name;
        other.name = nullptr;

        return *this;
    }

};