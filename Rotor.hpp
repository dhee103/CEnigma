#ifndef __ROTOR_H
#define __ROTOR_H

#include "Component.hpp"

/*
   The rotor class is a component which is used to represent the rotors. It
   contains a method to parse it, one to find the offset and makes use of the
   protected functions shouldNextRotorTurn() and getNumTurns()
*/
class Rotor : public Component
{
public:
//    Rotor(std::vector<int>* config);
    Rotor(char *arg);
    bool shouldNextRotorTurn();
    int getNumTurns();

private:
    int numTurns;
    void findOffsets();
    void parseRotor(char *arg);
};

#endif
