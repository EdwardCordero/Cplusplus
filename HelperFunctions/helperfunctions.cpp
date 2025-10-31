#include <iostream>
#include "helperfunctions.h"

size_t stringLen(const char* str)
{
    size_t i = 0;
    char c = str[i];
    while(c != '\0')
    {
        i++;
        c = str[i];
    }

    return i;
}

char** generateDefaultStringArray()
{
    int ns = 5;
    const char* strings[] = { "Edward", "Test", "Test", "Start", "End"} ;
    char** arr = new char*[ns + 1];     // +1 for nullptr to mark the end of arr

    for(int i = 0; i < ns; i++)
    {
        int numChars = stringLen(strings[i]);
        char* newString = new char[numChars+1];
        for(int j = 0; j < numChars; j++)
        {
            char c = strings[i][j];
            newString[j] = c;
        }
        newString[numChars] = '\0';
        arr[i] = newString;
    }

    arr[ns] = nullptr;
    return arr;
}

int* generateDefaultIntArray(int size)
{
    int nn = size;
    int* nums = new int[nn]{ 89, 5443, 1, 100, 23 };
    return nums;
}

// template <typename T>
// void printArr(T** arr)
// {
//     for(int i = 0; arr[i] != nullptr; i++)
//     {
//         std::cout << arr[i] << std::endl;
//     }
// }

// template <typename T>
// void printArr(T* arr, int size)
// {
//     for(int i = 0; i < size; i++)
//     {
//         std::cout << arr[i] << std::endl;
//     }
// }

// template <typename T>
// void cleanupArr(T** arr)
// {
//     for(int i = 0; arr[i] != nullptr; i++)
//     {
//         delete[] arr[i];
//     }

//     delete[] arr;
// }

// template <typename T>
// void cleanupArr(T* arr)
// {
//     delete[] arr;
// }