#ifndef __PLUGBOARD_H
#define __PLUGBOARD_H

#include "Component.hpp"
#include <vector>
#include <string>

/*
   The plugboard class is a component which is used to represent the
   plugboard and contains a method to parse it
*/
class Plugboard : public Component
{
public:
    Plugboard(char *stream);
    bool shouldNextRotorTurn() { return false; }
    int getNumTurns() { return -1; }
private:
    std::vector<int>* config;
    void parsePlugboard(char *stream);
};

#endif
