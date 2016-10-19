#include "Reflector.hpp"
#define ALPHABET_SIZE 26
#define OFFSET 13

Reflector::Reflector() {
    forward = new std::vector<int>;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        forward->push_back(OFFSET);
    }
}
