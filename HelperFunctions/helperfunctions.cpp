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

/// @brief Creates char array with 5 strings 
/// @return 
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

/// @brief Set size between 1-12 for now, will add random generator later
/// @param size
/// @return 
int* generateDefaultIntArray(int size)
{
    const int intPool[] = {1, 30, 405, 57, 24324, 94, 3, 53, 17, 8, 70, 1023};
    int nn = size;
    int* nums = new int[nn];
    for(int i = 0; i < size; i++)
    {
        nums[i] = intPool[i];
    }
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