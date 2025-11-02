#include <iostream>
#include "..\HelperFunctions\helperfunctions.h"

int main(int argsc, char** argsv)
{
    int arrSize;
    std::cout << "Enter size for int array 1-12 only" << std::endl;
    std::cin >> arrSize;

    int* intArr = generateDefaultIntArray(arrSize);
    printArr(intArr, arrSize);
}