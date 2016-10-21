#include "Reflector.hpp"
#define OFFSET 13

// constructor for reflector which pushes the offset onto the reflector
Reflector::Reflector()
{
    forward = new std::vector<int>;
    for (int i = 0; i < ALPHABET_SIZE; i++) { forward->push_back(OFFSET); }
}
