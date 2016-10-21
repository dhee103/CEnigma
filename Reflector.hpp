#ifndef __REFLECTOR_H
#define __REFLECTOR_H

#include "Component.hpp"

/*
   The reflector class is a component which is used to represent the
   reflector.
*/
class Reflector : public Component
{
public:
    Reflector();
    bool shouldNextRotorTurn() { return false; };
    int getNumTurns() { return -1; };
};

#endif
