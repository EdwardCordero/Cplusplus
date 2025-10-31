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

bool stringcompare(const char* a, const char* b)
{
    int i = 0;
    while(a[i] != '\0')
    {
        if(a[i] != b[i])
        {
            return false;
        }
        i++;
    }
    if(b[i] != '\0')
    {
        return false;
    }

    return true;
}

int findChar(const char* str, char c)
{
    for(int i = 0; i < stringLen(str); i++)
    {
        if(str[i] == c)
        {
            return i;
        }
    }

    return -1;
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
    int* maxPtr = &nums[0];
    int* minPtr = &nums[0];
    for(int i = 0; i < size; i++)
    {
        int* currentNum = &nums[i];
        if(*currentNum > *maxPtr)
        {
            maxPtr = currentNum;
        }
        if(*currentNum < *minPtr)
        {
            minPtr = currentNum;
        }
    }

    std::cout << "Max: " << *maxPtr << " at address: " << maxPtr << std::endl;
    std::cout << "Min: " << *minPtr << " at address: " << minPtr << std::endl;
}

template <typename T>
T* copyPtr(T* destination, T* src, int size)
{
    for(int i = 0; i < size; i++)
    {
        destination[i] = src[i];
    }

    if(std::is_same_v<T, char>)
    {
        destination[size] = '\0';
    }

    return destination;
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

void countVowelsAndConsonants(const char* str)
{
    int vc = 0, cc = 0;
    int i = 0;
    char c = std::tolower(str[i]);

    while(c != '\0')
    {
        if((c =='a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
        {
            vc++;
        }
        else{
            cc++;
        }

        i++;
        c = std::tolower(str[i]);
    }

    std::cout << str << " Num of Vowels: " << vc << " Num of Consonants: " << cc << std::endl;
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
    int* nums = generateDefaultIntArray(size);
    // Print both arrays
    //printArr<int>(nums, size);
    //printArr<char>(arr);

    // Logic
    for(int i = 0; arr[i] != nullptr; i++)
    {
        countVowelsAndConsonants(arr[i]);
    }

    // Clean up
    cleanupArr(arr);
    cleanupArr(nums);
}