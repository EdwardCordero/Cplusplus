#include <iostream>
#include "..\HelperFunctions\helperfunctions.h"
#include "..\DataStructures\datastructs.h"

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
    uVector<int> intArr = {1,2,3,4};
    uVector<const char*> charArr = {"Test", "End", "Start", "duck"};

    //printArr(intArr.data, intArr.size);
    //printArr(charArr.data, charArr.size);

    charArr.pop();
    //printArr(charArr.data, charArr.size);

    intArr.push(100);
    intArr.push(42342);
    //printArr(intArr.data, intArr.size);

    uVector<int> secondIntArr;
    secondIntArr = intArr;

    printArr(secondIntArr.data, secondIntArr.size);

    uVector<const char*> newCharArr(std::move(charArr));
    printArr(newCharArr.data, newCharArr.size);

    if(charArr.data == nullptr)
    {
        std::cout << "Sucessfully moved charArr to newCharArr" << std::endl;
    }

    newCharArr.push("duck");
    newCharArr.push("book");
    newCharArr.push("flower");
    printArr(newCharArr.data, newCharArr.size);


    charArr = std::move(newCharArr);
    printArr(charArr.data, charArr.size);

    if(newCharArr.data == nullptr)
    {
        std::cout << "Sucessfully moved newCharArr to charArr" << std::endl;
    }

    newCharArr.push("uncanny");
    newCharArr.push("Bee");
    newCharArr.push("Cup");

    printArr(newCharArr.data, newCharArr.size);
}