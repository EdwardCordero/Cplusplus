#pragma once

size_t stringLen(const char* str);

char** generateDefaultStringArray();

int* generateDefaultIntArray(int size);

template <typename T>
void printArr(T** arr)
{
    for(int i = 0; arr[i] != nullptr; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

template <typename T>
void printArr(T* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

template <typename T>
void cleanupArr(T** arr)
{
    for(int i = 0; arr[i] != nullptr; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}

template <typename T>
void cleanupArr(T* arr)
{
    delete[] arr;
}