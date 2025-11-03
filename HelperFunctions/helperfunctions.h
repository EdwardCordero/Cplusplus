#pragma once

size_t stringLen(const char* str);

char** generateDefaultStringArray();

int* generateDefaultIntArray(int size);

template <typename T>
bool resizeArr(T*& arr, int newSize)
{
    T* newArr = static_cast<T*>(realloc(arr, newSize * sizeof(T)));
    if(newArr == NULL)
    {
        std::cout << "Failed to realloc array size to new size of: " << newSize << std::endl;
        return false;
    }

    arr = newArr;
    return true;
}

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