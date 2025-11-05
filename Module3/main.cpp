#include <iostream>
#include "..\HelperFunctions\helperfunctions.h"
#include "..\DataStructures\person.h"

int main(int argsc, char** argsv)
{
    Person person = "Edward";
    std::cout << person.name << std::endl;

    person = "Bob";
    
    std::cout << person.name << std::endl;

    Person newPerson(person);

    std::cout << newPerson.name << std::endl;

    Person copyPerson = Person();
    copyPerson = std::move(person);

    std::cout << "Copy " << copyPerson.name << std::endl;

    if(person.name == nullptr)
    {
        std::cout << "Original is blank" << std::endl; 
    }

    person = "Testinglongstringstringstinrg";
    std::cout << person.name << std::endl;

    copyPerson = person;

    std::cout << copyPerson.name << std::endl;
    
    return 0;
}