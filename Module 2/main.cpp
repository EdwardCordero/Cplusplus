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
    // int orignalSize = 12;
    // int* intArr = generateDefaultIntArray(orignalSize);
    // int newSize = 20;
    // bool status = resizeArr<int>(&intArr, 20);
    int orignalSize = 5;
    char** charArr = generateDefaultStringArray();
    int newSize = 10;
    bool status = resizeArr<char*>(charArr, newSize);
    
    if(status)
    {
        for(int i = orignalSize; i < newSize; i++)
        {
            charArr[i] = nullptr;
            bool success = resizeArr<char>(charArr[i], 2);
            if(success)
            {
                charArr[i][0] = 'i';
                charArr[i][1] = '\0';
            }
        }

        charArr[newSize] = nullptr;
        printArr(charArr);
    }
    else{
        printArr(charArr);
    }
}