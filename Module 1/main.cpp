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

int main(int argc, char** argsv)
{
    const char* arr[] = {"Edward", "Test", "End", "Start"};

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        size_t len = stringLen(arr[i]) + 1;
        std::cout << "Length of " << arr[i] << ": " << len << std::endl;
        char* destination = new char[len];

        stringCopy(destination, arr[i]);
        std::cout << "Copy: " << destination << std::endl;
        delete[] destination;
    }
}