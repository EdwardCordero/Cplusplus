#include <iostream>
#include <type_traits>

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

void stringCopy(char* destination, const char* src)
{
    int j = 0;
    char c = src[j];

    while(c != '\0')
    {
        destination[j] = c;

        j++;
        c = src[j];
    }
    destination[j++] = '\0';
}

void reverseStr(char* str)
{
    int end = stringLen(str) - 1;
    int start = 0;
    char c = str[start];
    
    while(start <= end)
    {
        char sc = str[start];
        char ec = str[end];
        char temp = sc;

        str[start] = ec;
        str[end] = temp;

        start++;
        end--;
    }
}

void findMinMax(int* nums, int size)
{
    int maxIndex = 0, minIndex = 0;
    for(int i = 0; i < size; i++)
    {
        int currentNum = nums[i];
        if(currentNum > nums[maxIndex])
        {
            maxIndex = i;
        }
        if(currentNum < nums[minIndex])
        {
            minIndex = i;
        }
    }

    std::cout << "Max: " << nums[maxIndex] << " at index: " << maxIndex << std::endl;
    std::cout << "Min: " << nums[minIndex] << " at index: " << minIndex << std::endl;
}

void swapIntsInArr(int* nums, int size)
{
    std::cout << "Before Swap" << std::endl;
    for(int n = 0; n < size; n++)
    {
        std::cout << n << " Address: " << &nums[n] << " Value: " << nums[n] << std::endl;
    }

    int* end = &nums[size - 1];
    int* start = &nums[0];
    for(int i = 0; start < end; i++)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    std::cout << "After Swap" << std::endl;
    for(int n = 0; n < size; n++)
    {
        std::cout << n << " Address: " << &nums[n] << " Value: " << nums[n] << std::endl;
    }
}

char** generateDefaultStringArray()
{
    int ns = 4;
    const char* strings[] = { "Edward", "Test", "End", "Start"} ;
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

int main(int argc, char** argsv)
{
    // generate char*[] and int[] arrays
    char** arr = generateDefaultStringArray();
    int size = 5;
    int* nums = generateDefaultIntArray(5);

    // Print both arrays
    printArr<int>(nums, size);
    //printArr<char>(arr);

    // Logic
    findMinMax(nums, size);

    // Clean up
    cleanupArr(arr);
    cleanupArr(nums);
}