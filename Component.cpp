#include "Component.hpp"
#include <stdlib.h>
#include <iostream>

Component::~Component() {
    free(forward);
    free(reverse);
}

void printVector(std::vector<int> *vector)
{
    for (unsigned int i = 0; i < vector->size(); i++)
    {
        std::cout << "value at " << i << " is: " << vector->at(i) << std::endl;
    }
}

int Component::getForwardsCharAsInt(int charAsNum)
{
    return (charAsNum + forward->at(charAsNum)) % ALPHABET_SIZE;
}

int Component::getBackwardsCharAsInt(int charAsNum)
{
//    int temp = charAsNum + ALPHABET_SIZE;
////    std::cout << "retrieval from reverse" << std::endl;
////    printVector(reverse);
////    std::cout << "vector print" << std::endl;
//    temp -= reverse->at(charAsNum);
////    std::cout << "successful retrieval" << std::endl;
//    temp %= ALPHABET_SIZE;
////    std::cout << "mod" << std::endl;
//    return temp;

    return (charAsNum + ALPHABET_SIZE - reverse->at(charAsNum)) % ALPHABET_SIZE;
}
