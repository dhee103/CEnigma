#include <cstdlib>
#include "Rotor.hpp"
#include <algorithm>
#include <sstream>

Rotor::Rotor(std::string rotorStream)
{
    parseRotorFile(rotorStream);
    this->numTurns = 0;
    findOffsets();

}

Rotor::~Rotor() {
    delete(forward);
}

void Rotor::parseRotorFile(std::string rotorString) {
//    string to char array
    int n;
    std::stringstream stream(rotorString);
    while(stream >> n){
        forward->push_back(n);
    }
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




