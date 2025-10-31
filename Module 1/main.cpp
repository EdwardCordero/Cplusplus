#include <iostream>

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

char** generateDefaultStringArray()
{
    int ns = 4;
    char* strings[] = { "Edward", "Test", "End", "Start"} ;
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

template <typename T>
void printArr(T** arr)
{
    for(int i = 0; arr[i] != nullptr; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

int main(int argc, char** argsv)
{
    char** arr = generateDefaultStringArray();

    for(int i = 0; arr[i] != nullptr; i++)
    {
        reverseStr(arr[i]);
    }

    printArr(arr);
    
    delete[] arr;
}