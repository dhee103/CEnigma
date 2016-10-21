#include <cstdlib>
#include "Rotor.hpp"
#include <algorithm>
#include <iostream>

// Creates a rotor object with correct initialisation
Rotor::Rotor(char *arg)
{
    parseRotor(arg);
    this->numTurns = 0;
    findOffsets();
}

/*
   Parses the char* passed to get the result of the rotor on the user input
   in forward
*/
void Rotor::parseRotor(char *arg)
{
    std::vector<int> *config = new std::vector<int>;
    std::ifstream rotorFile(arg);
    if (rotorFile)
    {
        int value;
        while (rotorFile >> value) config->push_back(value);
        forward = config;
        rotorFile.close();
    }
    else { std::cerr << "not a rotor file"; exit(1); }
}

/*
   As titled, the function finds the offsets and adds them appropriately to
   forward
*/
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

/*
   Turns the current rotor and based on the number of turns it will decide if
   the next turn should be for the following rotor (numTurns == 26) or the
   current one
*/
bool Rotor::shouldNextRotorTurn()
{
    std::rotate(forward->begin(), forward->begin()+1, forward->end());
    for (unsigned int start = 0; start < forward->size(); start++)
    {
        int end = (start + forward->at(start)) % ALPHABET_SIZE;
        reverse->at(end) = forward->at(start);
    }

    numTurns++;
    if (numTurns == 26)
    {
        numTurns = 0;
        return true;
    }
    return false;
}

int Rotor::getNumTurns() { return numTurns; }



