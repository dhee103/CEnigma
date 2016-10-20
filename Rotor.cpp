#include <cstdlib>
#include "Rotor.hpp"
#include <algorithm>

Rotor::Rotor(std::ifstream rotorFile)
{
    this->forward = parseRotorFile(rotorFile);
    this->numTurns = 0;
    findOffsets();

}

Rotor::~Rotor() {
    delete(forward);
}

std::vector<int>* Rotor::parseRotorFile(std::ifstream rotorFile) {
    int value;
    while (rotorFile >> value) { this->forward->push_back(value); }
    rotorFile.close();
}

void Rotor::findOffsets()
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        int val = forward->at(i);
        forward->at(i) = (val + ALPHABET_SIZE - i) % ALPHABET_SIZE;
    }

    reverse = new std::vector<int>;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        reverse->push_back(0);
    }

    for (unsigned int start = 0; start < forward->size(); start++) {
        int end = (start + forward->at(start)) % ALPHABET_SIZE;
        reverse->at(end) = forward->at(start);
    }
}

bool Rotor::shouldRotorTurn()
{
    std::rotate(forward->begin(), forward->begin()+1, forward->end());
    for (unsigned int start = 0; start < forward->size(); start++) {
        int end = (start + forward->at(start)) % ALPHABET_SIZE;
        reverse->at(end) = forward->at(start);
    }

    numTurns++;
    if (numTurns == 26) {
        numTurns = 0;
        return true;
    }
    return false;
}

int Rotor::getNumTurns() { return numTurns; }




