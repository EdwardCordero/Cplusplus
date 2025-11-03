#include <iostream>
#include "..\HelperFunctions\helperfunctions.h"

char* duplicateStr(const char* originalStr)
{
    int oSize = stringLen(originalStr) + 1; // +q for null term char
    char* dupStr = (char*)malloc(oSize);

    for(int i = 0; i <= oSize; i++)
    {
        dupStr[i] = originalStr[i];
    }

    return dupStr;
}

char* concatStrs(const char* firstStr, const char* secStr)
{
    int fSize = strlen(firstStr);
    int sSize = strlen(secStr) + 1;
    int maxSize = fSize + sSize;
    char* newStr =  (char*)malloc(maxSize);

    int i = 0, j = fSize;
    while(i < maxSize)
    {
        if(i < fSize)
        {
            newStr[i] = firstStr[i];
        }
        if(i < sSize)
        {
            newStr[j] = secStr[i];
            j++;
        }
        i++;
    }

    newStr[j+1] = '\0';

    return newStr;
}

int main(int argsc, char** argsv)
{
    char** charArr = generateDefaultStringArray();

    char* dupStr = concatStrs(charArr[0], charArr[1]);

    int i = 0;
    while(i <= stringLen(dupStr))
    {
        if(dupStr[i] == '\0')
        {
            std::cout << "\\0";
        }
        std::cout << dupStr[i];
        i++;
    }
}