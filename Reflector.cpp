#include "Reflector.hpp"
#define OFFSET 13

Reflector::Reflector() {
    forward = new std::vector<int>;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        forward->push_back(OFFSET);
    }
}

bool Reflector::shouldRotorTurn() { return false; }
int Reflector::getNumTurns() { return -1; }

