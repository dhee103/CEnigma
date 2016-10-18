#include <cstdlib>
#include "Rotor.hpp"

Rotor::Rotor(std::vector<int> *config)
{
    this->forward = config;
    this->numTurns = 0;
}

bool Rotor::shouldRotorTurn() {
    return false;
}

int Rotor::getNumTurns() {
    return this->numTurns;
}

