#include <iostream>

template <typename T>
T stringToInt(const char* str)
{
    int i = 0, sign = 1;
    T ans = 0;
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    char c = str[i];
    bool decimalPlace = false;
    int divisor = 1;
    int dIndex = 1;
    while(c != '\0')
    {
        if(c == '.') {
            if(!decimalPlace) {decimalPlace = true; i++; c = str[i];}
            else{ return -1; }
        }
        float diff = c - '0'; // This return int bc x - '0' = x in int 
        if(!decimalPlace)
        {
            ans = diff + (ans * 10);
        }
        else{
            divisor *= 10;
            ans = ans + (diff / divisor);
        }
        i++;
        c = str[i];
    }
    return ans * sign;
}

int main(char* args[])
{
    const char* strArr[] = {"Test", "End", "Edward", "Cplusplus"};
    const char* numArr[] = {"01", "10", "28", "-321", "-2", "1232.72"};
    for(int i = 0; i < sizeof(numArr)/sizeof(numArr[0]); i++)
    {
        std::cout << stringToInt<float>(numArr[i]) << std::endl;
    }
}