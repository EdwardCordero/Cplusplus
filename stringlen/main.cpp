#include <iostream>

int stringLen(const char* str)
{
    int i = 0;
    char c = str[i];
    while(c != '\0')
    {
        i++;
        c = str[i];
    }

    return i;
}

int main(int argc, char** argsv)
{
    const char* arr[] = {"Edward", "Test", "End", "Start"};

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        std::cout << "Length of " << arr[i] << ": " << stringLen(arr[i]) << std::endl;
    }
}